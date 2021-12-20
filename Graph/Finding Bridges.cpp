/**    Success is not a Miracle,
                                      it's a journey of DEDICATION  **/
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
vector <int> arr[10001];
int vis[10001],in[10001],low[10001],timer;

void dfs(int node,int par)
{
    vis[node] = 1;
    in[node] = low[node] = timer;
    timer++;

    for(int child : arr[node])
    {
        if(child == par)
        {
            continue;
        }
        if(vis[child] == 1)
        {
            // edge node - child is a back edge

            low[node] = min(low[node],in[child]);
        }
        else
        {
            // edge node - child is a forward edge

            dfs(child,node);
            if(low[child] > in[node])
            {
                cout << node << " -> " << child << " is a bridge" << endl;
            }
            low[node] = min(low[node],low[child]);
        }
    }
}

void solve()
{
    int n,m,a,b,i;
    cin >> n >> m;
    for(i=1; i<=m; i++)
    {
        cin >> a >> b;
        arr[a].pb(b);
        arr[b].pb(a);
    }
    dfs(1,-1);
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
4 4
1 2
2 3
2 4
3 4
Output :
1 -> 2 is a bridge
**/
