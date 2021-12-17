// Bipartite Graph is also known as Bigraph special graph such that you can divide vertex into
// 2 disjoints such that :
// 1. Each vertex belongs to exactly one of 2 sets
// 2. Each edge connect vertices of 2 different sets
// Notes : if graph contain odd length cycle then this graph never be bipartite graph.

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
int vis[100001],col[100001];

bool dfs(int node,int c)
{
    vis[node] = 1;
    col[node] = c;
    for(int child : arr[node])
    {
        if(!vis[child])
        {
            if(dfs(child,c^1)==false)
            {
                return false;
            }
        }
        else
        {
            if(col[node]==col[child])
            {
                return false;
            }
        }
    }
    return true;
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

    if(dfs(1,1))
    {
        cout << "Yes graph is Bipartite" << endl;
    }
    else
    {
        cout << "No graph is not Bipartite" << endl;
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
5 5
1 2
2 3
2 4
3 4
4 5
Output :
No graph is not Bipartite

Input :
5 4
1 2
2 3
2 4
4 5
output :
Yes graph is Bipartite
**/
