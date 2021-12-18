/*
 *
 * FILE: C.cpp
 *
 * Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh (H S T U).
 *
 * Name        : Sourav Roy (Shuvo)
 *
 * Department  : Computer Science and Engineering (Batch - CSE'19)
 *
 * Email       : souravkumarroy813965@gmail.com
 *
 */

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
vector <int> adj[100001];
int vis[100001],subsize[100001];

int dfs(int node)
{
    vis[node] = 1;
    int curr = 1;
    for(int child : adj[node])
    {
        if(!vis[child])
        {
            curr += dfs(child);
        }
    }
    subsize[node] = curr;
    return curr;
}

void solve()
{
    int n,m,i,a,b;
    cin >> n >> m;
    for(i=1; i<=m; i++)
    {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int x = dfs(1);
    for(i=1; i<=n; i++)
    {
        cout << subsize[i] << " ";
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    while(t--)
    {
        solve();
    }
}
/**
Test Case :
Input :
7 6
1 2
2 3
2 4
3 7
4 5
4 6
Output :
7 6 2 3 1 1 1
**/
