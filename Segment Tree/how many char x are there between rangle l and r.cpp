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
int st[30][800005],lazy[30][800005];
char str[200005];
// amra segment tree er ekta range er value purai change kore dicchi tai += hbe na ekhane

int query(int si,int ss,int se,int qs,int qe,int ch)
{
    if(lazy[ch][si] != 0)
    {
        int dx = lazy[ch][si];
        lazy[ch][si] = 0;
        st[ch][si] = (dx % 2) * (se - ss + 1);

        if(ss != se)
        {
            lazy[ch][2*si] = dx;
            lazy[ch][2*si+1] = dx;
        }
    }

    if(ss > qe || se < qs)
    {
        return 0;
    }

    if(ss >= qs && se <= qe)
    {
        return st[ch][si];
    }

    int mid = (ss + se) / 2;
    return query(2*si , ss , mid , qs , qe , ch) + query(2*si+1 , mid+1 , se , qs , qe , ch);
}

void update(int si,int ss,int se,int qs,int qe,int ch,int val)
{
    if(lazy[ch][si] != 0)
    {
        int dx = lazy[ch][si];
        lazy[ch][si] = 0;
        st[ch][si] = (dx % 2) * (se - ss + 1);

        if(ss != se)
        {
            lazy[ch][2*si] = dx;
            lazy[ch][2*si+1] = dx;
        }
    }

    if(ss > qe || se < qs)
    {
        return;
    }

    if(ss >= qs && se <= qe)
    {
        int dx = (se - ss + 1) * (val % 2);
        st[ch][si] = dx;

        if(ss != se)
        {
            lazy[ch][2*si] = val;
            lazy[ch][2*si+1] = val;
        }
        return ;
    }

    int mid = (ss + se) / 2;
    update(2*si , ss , mid , qs , qe , ch , val);
    update(2*si+1 , mid+1 , se , qs , qe , ch , val);
    st[ch][si] = st[ch][2*si] + st[ch][2*si+1];
}

void solve()
{
    int n,q,i,j,l,r,k;
    cin >> n >> q;
    char c;
    for(i=1; i<=n; i++)
    {
        cin >> str[i];
        update(1 , 1 , n , i , i , str[i] - 'a' , 1);
    }
    while(q--)
    {
        cin >> l >> r >> k;
        int cnt[30];
        if(k)
        {
            for(i=0; i<26; i++)
            {
                cnt[i] = query(1 , 1 , n , l , r , i);
                if(!cnt[i])
                {
                    continue;
                }
                update(1 , 1 , n , l , r , i , 2);
            }
            for(i=0; i<26; i++)
            {
                if(cnt[i])
                {
                    update(1 , 1 , n , l , l+cnt[i]-1 , i , 1);
                    l += cnt[i];
                }
            }
        }
        else
        {
            for(i=25; i>=0; i--)
            {
                cnt[i] = query(1 , 1 , n , l , r , i);
                if(!cnt[i])
                {
                    continue;
                }
                update(1 , 1 , n , l , r , i , 2);
            }
            for(i=25; i>=0; i--)
            {
                if(cnt[i])
                {
                    update(1 , 1 , n , l , l+cnt[i]-1 , i , 1);
                    l += cnt[i];
                }
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=0; j<26; j++)
        {
            if(query(1 ,1 , n , i , i , j))
            {
                str[i] = j + 'a';
                break;
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        cout << str[i];
    }
    cout << endl;
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



