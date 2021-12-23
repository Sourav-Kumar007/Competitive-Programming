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
// Graph on 2D Grid //
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int vis[1001][1001];
int n,m;

bool isvalid(int x,int y)
{
    if(x<1 || x>n || y<1 || y>n)
    {
        return false;
    }

    if(vis[x][y])
    {
        return false;
    }

    return true;
}

void dfs(int x,int y)
{
    vis[x][y] = 1;
    cout << x << " " << y << endl;

    for(int i =0; i<4; i++)
    {
        if(isvalid(x+dx[i] , y+dy[i]))
        {
            dfs(x+dx[i] , y+dy[i]);
        }
    }
}

void solve()
{
    cin >> n >> m;
    dfs(1,1);
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
