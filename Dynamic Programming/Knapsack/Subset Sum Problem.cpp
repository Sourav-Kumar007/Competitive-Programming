// In this problem you are given an array and integer. Now you have to find how many subset there are in that array
// whose sum is equal to that given integer. This is the very famous dynamic programming problem. For this problem
// i write DP Top-Down approach. Here dp[i][j] means is it possible to get subset sum j for first i element of the
// array. Mainly i divide the whole problem into many sub problems and after that i merge all the solution of that
// sub problem and find out the final result.

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
                dp[i][j] = (dp[i-1][j-arr[i]] || dp[i-1][j]);
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

    if(SubSet(n,sum))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
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
5 11
2 3 5 8 11

Output :
Yes
**/
