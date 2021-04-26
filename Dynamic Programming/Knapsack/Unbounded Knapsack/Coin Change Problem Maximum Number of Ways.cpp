// In this problem you are given an array and you have to calculate how many ways there are to find that sum.

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
int arr[1001];

int MaxWays(int n,int coin)
{
    int dp[n+1][coin+1],i,j;

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=coin; j++)
        {
            if(i==0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=coin; j++)
        {
            if(j==0)
            {
                dp[i][j] = 1;
            }
        }
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=coin; j++)
        {
            if(arr[i]<=j)
            {
                dp[i][j] = dp[i][j-arr[i]] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][coin];
}

void solve()
{
    int n,coin,i;
    cin >> n >> coin;

    for(i=1; i<=n; i++)
    {
        cin >> arr[i];
    }

    cout << MaxWays(n,coin) << endl;
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
3 5
1 2 3

Output :
5

Input :
5 6
1 2 3 4 5

Output :
10
**/
