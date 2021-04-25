// This is the Top Down approach of the Knapsack problem. In this problem we used 2D Matrix to store the result
// and reuse that result later. here dp[i][j] means the maximum price we can get when we are in ith weight from
// starting. Mainly this code find out all the optimal result for any n and w ..then finally we got the result.

/**
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh (H S T U).
      Name        : Sourav Roy (Shuvo)
      Department  : Computer Science and Engineering (Batch - CSE'19)
      Email       : souravkumarroy813965@gmail.com
**/


#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define all(a) a.begin(),a.end()
#define pb push_back
#define mod 1000000007
int dp[102][1002],weight[1002],price[1002];

int knapsack(int n,int w)
{
    int i,j;

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=w; j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=w; j++)
        {
            if(weight[i]<=j)
            {
                dp[i][j] = max(price[i] + dp[i-1][j-weight[i]],dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }

        }
    }


    return dp[n][w];

}

void solve()
{
    int n,w,i;
    cin >> n >> w;

    for(i=1; i<=n; i++)
    {
        cin >> weight[i];
    }
    for(i=1; i<=n; i++)
    {
        cin >> price[i];
    }

    cout << knapsack(n,w) << endl;
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
8 10
4 3 9 12 2 6 8 8
1 2 3 3 2 1 1 2

output :
5
**/
