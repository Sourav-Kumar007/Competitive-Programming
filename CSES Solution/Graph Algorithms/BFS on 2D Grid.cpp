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
int n,m,i,j;
int vis[100][100],dist[100][100];

bool isValid(int x,int y)
{
    if(x<1 || x>n || y<1 || y>m)
    {
        return false;
    }

    if(vis[x][y])
    {
        return false;
    }

    return true;
}

void bfs(int srcX,int srcY)
{
    queue <pair <int,int> > q;
    vis[srcX][srcY] = 1;
    dist[srcX][srcY] = 0;
    q.push({srcX,srcY});

    while(!q.empty())
    {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for(i=0; i<4; i++)
        {
            if(isValid(currX+dx[i], currY+dy[i]))
            {
                int newX = currX + dx[i];
                int newY = currY + dy[i];

                q.push({newX,newY});
                dist[newX][newY] = dist[currX][currY] + 1;
                vis[newX][newY] = 1;
            }
        }
    }

    cout << "Distance Array : " << endl;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

void solve()
{
    int x,y;
    cin >> n >> m; // enter dimension of the 2D array
    cin >> x >> y;  // on which cell you want to run bfs
    bfs(x,y);
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
4 4 1 1
Output :
Distance Array :
0 1 2 3
1 2 3 4
2 3 4 5
3 4 5 6

Input :
7 7 4 4
Output :
Distance Array :
6 5 4 3 4 5 6
5 4 3 2 3 4 5
4 3 2 1 2 3 4
3 2 1 0 1 2 3
4 3 2 1 2 3 4
5 4 3 2 3 4 5
6 5 4 3 4 5 6
**/

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/

