#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
//#define int long long
#define all(a) a.begin(),a.end()
#define pb push_back
#define mod 1000000007
#define inf 1e18
#define ppb pop_back
#define ff first
#define ss second
#define mx 1000013

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
int sp[mx],marked[mx];
int arr[mx],vis[mx],cnt;
vector <int> adj[mx],curr[mx];

void sieve()
{
    int i,j,x;
    for(i=2; i<mx; i+=2)
    {
        sp[i] = 2;
    }
    for(i=3; i<mx; i+=2)
    {
        sp[i] = i;
    }
    x = sqrt(mx);
    for(i=3; i<x; i++)
    {
        if(sp[i] == i)
        {
            for(j=i*i; j<mx; j+=i)
            {
                sp[j] = i;
            }
        }
    }
}

void dfs(int node)
{
    vis[node] = 1;
    cnt++;
    for(int child : adj[node])
    {
        if(!vis[child])
        {
            dfs(child);
        }
    }
}

void solve()
{
    int n,i,u,v,x,ans=0;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> x;
        vis[i]++;
        while(x > 1)
        {
            int pm = sp[x];
            curr[pm].pb(i);
            while(x % pm == 0)
            {
                x /= pm;
            }
        }
    }
    for(i=1; i<n; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector <int> primes;

    for(i=2; i<mx; i++)
    {
        if(sp[i] == i)
        {
            primes.pb(i);
        }
    }
    for(auto it : primes)
    {
        for(int node : curr[it])
        {
            vis[node] = 0;
        }
        if(curr[it].size() == 0)
        {
            continue;
        }
        for(int i : curr[it])
        {
            cnt = 0;
            if(!vis[i])
            {
                dfs(i);
                ans = max(ans , cnt);
            }
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve();
    int t = 1;
    while(t--)
    {
        solve();
    }
}
/**
Test Case :

**/

