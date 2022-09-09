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
const int maxN = 20;
int lca[300000][maxN+5],dist[300000];
vector <int> adj[300000];

void dfs(int node,int level,int par)
{
    dist[node] = level;
    lca[node][0] = par;
    for(int child : adj[node])
    {
        if(child != par)
        {
            dfs(child, level+1, node);
        }
    }
}

void init(int n)
{
    dfs(1, 0, -1);
    int i,j;

    for(i=1; i<=maxN; i++)
    {
        for(j=1; j<=n; j++)
        {
            lca[j][i] = -1;
        }
    }

    for(i=1; i<=maxN; i++)
    {
        for(j=1; j<=n; j++)
        {
            int par = lca[j][i-1];
            lca[j][i] = lca[par][i-1];
        }
    }
}

int getLCA(int a,int b)
{
    if(dist[b] < dist[a])
    {
        swap(a,b);
    }
    int d = dist[b] - dist[a];
    while(d)
    {
        int mx = log2(d);
        b = lca[b][mx];
        d -= (1 << mx);
    }

    if(a == b)
    {
        return a;
    }

    for(int i=maxN; i>=0; i--)
    {
        if(lca[a][i] != -1 && (lca[a][i] != lca[b][i]))
        {
            a = lca[a][i];
            b = lca[b][i];
        }
    }
    return lca[a][0];
}

int getdist(int a,int b)
{
    int LCA = getLCA(a,b);
    return dist[a] + dist[b] - (2 * dist[LCA]);
}

void solve()
{
    int n,i,u,v,q,k;
    cin >> n;
    for(i=1; i<n; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    init(n);
    cin >> q;
    while(q--)
    {
        cin >> k;
        int arr[k+5],left=-1,maxi=0,right=-1;
        for(i=1; i<=k; i++)
        {
            cin >> arr[i];
            if(dist[arr[i]] > maxi)
            {
                left = arr[i];
                maxi = dist[arr[i]];
            }
        }
        maxi = 0;
        for(i=1; i<=k; i++)
        {
            if(getLCA(left,arr[i]) != arr[i])
            {
                if(dist[arr[i]] > maxi)
                {
                    maxi = dist[arr[i]];
                    right = arr[i];
                }
            }
        }
        if(right == -1)
        {
            cout << "YES" << endl;
        }
        else
        {
            int ok = 1;
            for(i=1; i<=k; i++)
            {
                if(getdist(left,arr[i]) + getdist(right,arr[i]) != getdist(left,right))
                {
                    ok = 0;
                    break;
                }
            }
            if(ok)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
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

