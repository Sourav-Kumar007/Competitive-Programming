// In this problem you are given an array and difference . you have to calculate the numbers of subset which
// difference is equal to that given difference. Let's see how i solve it.
// Subset1 - Subset2 = diff (given in question)
// Subset1 + Subset2 = Sum of the array (We know that)
// Hence, Subset1 = (diff + Sum of the array) / 2
// So we just need to calculate how many subsets there are whose sum is equal to Subset1 sum. and that will be the result.

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

int CountOfSubsetSum(int n,int arr[],int sum)
{
    int dp[n+1][sum+1],i,j;

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
    int n,i,sum=0,x,diff;
    cin >> n >> diff;
    int arr[n+4];

    for(i=1; i<=n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    x = (diff + sum) / 2;

    cout << CountOfSubsetSum(n,arr,x) << endl;
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
4 1
1 1 2 3

Output :
3
**/

