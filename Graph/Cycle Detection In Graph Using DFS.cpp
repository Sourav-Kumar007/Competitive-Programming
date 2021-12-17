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
int  vis[100001];

bool dfs(int node,int par)
{
    vis[node] = 1;
    for(int child : arr[node])
    {
        if(!vis[child])
        {
            if(dfs(child,node))
            {
                return true;
            }
        }
        else
        {
            if(child!=par)
            {
                return true;
            }
        }
    }
}

void solve()
{
    int n,i,m,a,b;
    cin >> n >> m;
    for(i=1; i<=m; i++)
    {
        cin >> a >> b;
        arr[a].pb(b);
        arr[b].pb(a);
    }

    if(dfs(1,-1))
    {
        cout << "Cycle is found" << endl;
    }
    else
    {
        cout << "No cycle is found" << endl;
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
Cylce is found

Input :
5 4
1 2
2 3
2 4
4 5
Output :
No cycle is found
**/
