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

void BFS(int src)
{
    queue <int> q;
    q.push(src);
    vis[src] = 1;
    dist[src] = 0;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(int child : arr[curr])
        {
            if(vis[child]==0)
            {
                q.push(child);
                vis[child] = 1;
                dist[child] = dist[curr] + 1;
            }
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

    BFS(1);
    cout << dist[n] << endl;
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
8 7
1 3
1 2
2 4
1 5
1 6
6 7
6 8
Output :
2
**/
