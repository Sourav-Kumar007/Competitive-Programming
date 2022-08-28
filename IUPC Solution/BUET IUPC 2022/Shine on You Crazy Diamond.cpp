#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define int long long
#define all(a) a.begin(),a.end()
#define pb push_back
#define mod 1000000007
#define inf 1e18
#define ppb pop_back
#define ff first
#define ss second
#define mx 1000007

///  order_of_key return number of elements less than x -> os.order_of_key(x)
///  cout << "oth element  : " << *os.find_by_order(0) << endl; so it returns value of index

int lcm(int x,int y)
{
    return (x * 1LL * y) / __gcd(x,y);
}

// Graph on 2D Grid
/*----------------------Graph Moves----------------*/
//const int dx[]={+1,-1,+0,+0};
//const int dy[]={+0,+0,+1,-1};
//const int dx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int dy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int dx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int dy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

#define debug(x); cerr << #x <<" "; _print(x); cerr << endl;

void _print(int t)
{
    cerr << t;
}
void _print(string t)
{
    cerr << t;
}
void _print(char t)
{
    cerr << t;
}
void _print(double t)
{
    cerr << t;
}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T> void _print(vector <T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T> void _print(set <T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T> void _print(multiset <T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V> void _print(map <T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
int cnt[2000000],marked[2000000];
int maxi[1000020][3];

void solve()
{
    int n,i,x,j,ans=0,l=-1,r=-1;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> x;
        cnt[x]++;
    }

    for(i=2; i<mx; i++)
    {
        for(j=i+i; j<mx; j+=i)
        {
            cnt[i] += cnt[j];
        }
    }

    vector <int> primes;
    primes.pb(2);
    for(i=3; i<mx; i+=2)
    {
        if(marked[i] == 0)
        {
            for(j=i*i; j<mx; j+=(i+i))
            {
                marked[j] = 1;
            }
        }
    }
    for(i=3; i<mx; i+=2)
    {
        if(marked[i] == 0)
        {
            primes.pb(i);
        }
    }
    int sz = primes.size();
    maxi[primes[sz-1]][0] = cnt[primes[sz-1]];
    maxi[primes[sz-1]][1] = primes[sz-1];

    for(i=sz-2; i>=0; i--)
    {
        if(cnt[primes[i]] >= maxi[primes[i+1]][0])
        {
            maxi[primes[i]][0] = cnt[primes[i]];
            maxi[primes[i]][1] = primes[i];
        }
        else
        {
            maxi[primes[i]][0] = maxi[primes[i+1]][0];
            maxi[primes[i]][1] = maxi[primes[i+1]][1];
        }
    }


    for(i=0; i<primes.size(); i++)
    {
        for(j=i+1; j<primes.size(); j++)
        {
            int mult = primes[i] * 1LL * primes[j];
            if(mult >= mx)
            {
                x = cnt[primes[i]] + maxi[primes[j]][0];
                if(x > ans)
                {
                    ans = x;
                    l = primes[i];
                    r = maxi[primes[j]][1];
                }
                break;
            }
            else
            {
                x = (cnt[primes[i]] + cnt[primes[j]]) - cnt[mult];
                if(x > ans)
                {
                    ans = x;
                    l = primes[i];
                    r = primes[j];
                }
            }
        }
    }

    cout << n - ans << endl;
    if(ans == 0)
    {
        cout << "2 3" << endl;
    }
    else
    {
        cout << l << " " << r << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while(t--)
    {
        solve();
    }
}
/**
Test Case :

**/

