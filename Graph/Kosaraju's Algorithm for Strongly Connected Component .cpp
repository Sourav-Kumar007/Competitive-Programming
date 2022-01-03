///    Success is not a Miracle , it's a journey of DEDICATION   ///

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

// Graph on 2D Grid
/*----------------------Graph Moves----------------*/
//const int dx[]={+1,-1,+0,+0};
//const int dy[]={+0,+0,+1,-1};
//const int dx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int dy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int dx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int dy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/
int vis[1001];
vector <int> arr[1001],tr[1001];
vector <int> order,scc;

void dfs(int node)
{
    vis[node] = 1;

    for(int child : arr[node])
    {
        if(!vis[child])
        {
            dfs(child);
        }
    }

    order.pb(node);
}

void dfs1(int node)
{
    vis[node] = 1;

    for(int child : tr[node])
    {
        if(!vis[child])
        {
            dfs1(child);
        }
    }

    scc.pb(node);
}

void solve()
{
    int n,m,a,b,i;
    cin >> n >> m;
    for(i=1; i<=m; i++)
    {
        cin >> a >> b;
        arr[a].pb(b);
        tr[b].pb(a);
    }

    // je node er in degree 0(zero) tar out time beshi hobe
    // first time dfs run kore amra 2nd time dfs je order a run korbo sei order ta sajabo
    for(i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }

    for(i=1; i<=n; i++)
    {
        vis[i] = 0;
    }
    reverse(all(order));

    for(i=0; i<n; i++)
    {
        scc.clear();
        if(!vis[order[i]])
        {
            cout << "dfs() called from " << order[i] << " and printing SCC : " << endl;
            dfs1(order[i]);
            for(auto it : scc)
            {
                cout << it << " " ;
            }
            cout << endl;
        }
    }
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
7 8
1 2
2 3
3 1
4 3
7 4
7 5
5 6
6 7
Output :
dfs() called from 5 and printing SCC :
6 7 5
dfs() called from 4 and printing SCC :
4
dfs() called from 1 and printing SCC :
2 3 1
**/

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/

