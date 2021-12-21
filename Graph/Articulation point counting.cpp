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
vector <int> arr[10005];
int vis[10005],in[10005],low[10005],timer;
set <int> AP;

void dfs(int node,int par)
{
    vis[node] = 1;
    in[node] = low[node] = timer;
    timer++;
    int child_cnt = 0;

    for(int child : arr[node])
    {
        if(child == par)
        {
            continue;
        }
        if(vis[child] == 1)
        {
            low[node] = min(low[node], in[child]);
        }
        else
        {
            dfs(child,node);
            low[node] = min(low[node], low[child]);
            child_cnt++;
            if(in[node] <= low[child] && par!=-1)
            {
                AP.insert(node);
            }
        }
    }

    if(par==-1 && child_cnt>1)
    {
        AP.insert(node);
    }
}

void solve()
{
    int n,m,a,b,i;
    while(1)
    {
        cin >> n >> m;
        if(n==0 || m==0)
        {
            break;
        }
        timer = 1;
        AP.clear();
        for(i=1; i<=n; i++)
        {
            arr[i].clear();
            vis[i] = in[i] = low[i] = 0;
        }
        for(i=1; i<=m; i++)
        {
            cin >> a >> b;
            arr[a].pb(b);
            arr[b].pb(a);
        }
        for(i=1; i<=n; i++)
        {
            if(vis[i]==0)
            {
                dfs(i,-1);
            }
        }
        cout << AP.size() << endl;
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

**/

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/

