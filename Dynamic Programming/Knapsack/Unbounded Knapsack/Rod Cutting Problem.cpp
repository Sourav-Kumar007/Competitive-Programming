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
int length[1001],price[1001];

int MaxProfit(int n,int rod_len)
{
    int dp[n+1][rod_len + 1],i,j;

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=rod_len; j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=rod_len; j++)
        {
            if(length[i]<=j)
            {
                dp[i][j] = max(price[i] + dp[i][j-length[i]] , dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][rod_len];
}

void solve()
{
    int n,rod_len,i;
    cin >> n >> rod_len;

    for(i=1; i<=n; i++)
    {
        cin >> length[i];
    }
    for(i=1; i<=n; i++)
    {
        cin >> price[i];
    }

    cout << MaxProfit(n,rod_len) << endl;
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
3 2 2

Output :
15

8 8
1 2 3 4 5 6 7 8
7 3 5 9 12 5 10 11
**/
