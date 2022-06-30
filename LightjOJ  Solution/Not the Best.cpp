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
#define inf 1e18+7
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
vector <pair <int,int> > adj[5005];
int dist_from_s[5005],dist_from_d[5005],q=1;

void dijkstra(int par, int n)
{
    priority_queue <pair <int,int>, vector <pair <int,int> >, greater <pair <int,int> > > q;
    q.push({0, par});
    for(int i=0; i<=n; i++)
    {
        dist_from_d[i] = inf;
    }
    dist_from_d[par] = 0;
    while(!q.empty())
    {
        int curr = q.top().second;
        int curr_dis = q.top().first;
        q.pop();
        for(pair <int,int> p : adj[curr])
        {
            if(curr_dis + p.second < dist_from_d[p.first])
            {
                dist_from_d[p.first] = curr_dis + p.second;
                q.push({dist_from_d[p.first],p.first});
            }
        }
    }
}

void solve()
{
    int n,i,r,u,v,w;
    cin >> n >> r;
    for(i=1; i<=r; i++)
    {
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    dijkstra(1, n);
    for(i=0; i<=n; i++)
    {
        dist_from_s[i] = dist_from_d[i];
    }
    dijkstra(n, n);

    int ans = inf;
    for(i=1; i<=n; i++)
    {
        for(pair <int,int> p : adj[i])
        {
            int dis = dist_from_s[i] + dist_from_d[p.first] + p.second;
            if(dis > dist_from_s[n])
            {
                ans = min(ans, dis);
            }
        }
    }

    cout << "Case " << q++ << ": " << ans << endl;
    for(i=0; i<=n; i++)
    {
        adj[i].clear();
        dist_from_s[i] = dist_from_d[i] = 0;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
/**
Test Case :

**/
///  stuck in finding min / max problem ? think for binary search
///  special case : n = 1 ?
///  try to think in a different way or take a brake from pc and walk away
/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
