// “Success is not final, failure is not fatal: it is the courage to continue that counts.” — Winston Churchill

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
int dp[2002][2002],arr[1000];

int SubSet(int n,int sum)
{
    int i,j;

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=sum; j++)
        {
            if(i==0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=sum; j++)
        {
            if(j==0)
            {
                dp[i][j] = 1;
            }
        }
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=sum; j++)
        {
            if(arr[i]<=j)
            {
                dp[i][j] = (dp[i-1][j-arr[i]] + dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

void solve()
{
    int n,i,sum;
    cin >> n >> sum;
    for(i=1; i<=n; i++)
    {
        cin >> arr[i];
    }

    cout <<SubSet(n,sum) << endl;
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
5 10
2 3 5 8 10

Output :
3
**/
