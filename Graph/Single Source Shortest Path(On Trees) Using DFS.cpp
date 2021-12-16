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
vector <int> arr[100001];
int vis[100001],dist[100001];

int dfs(int node,int d)
{
    vis[node] = 1;
    dist[node] = d;
    for(int child : arr[node])
    {
        if(!vis[child])
        {
            dfs(child,d+1);
        }
    }
}

void solve()
{
    int n,m,i,a,b;
    cin >> n >> m;
    for(i=1; i<=m; i++)
    {
        cin >> a >> b;
        arr[a].pb(b);
        arr[b].pb(a);
    }

    dfs(1,0);
    for(i=2; i<=n; i++)
    {
        cout << dist[i] << " ";
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

**/
