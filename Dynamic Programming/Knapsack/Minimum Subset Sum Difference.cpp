// In this problem you are given an array and you have to find two subset which sum is minimum possible.
// We can solve this problem with the help of find Subset sum problem. We calculate total sum of the array
// and then check for 1 to total_sum/2 whether we can find this sum for a subset or not. and then we calculate
// the minimum value. So to get more information watch Aditya Verma's tutorial.

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
int total;

int MinSum(int arr[],int n,int sum)
{
    int dp[n+2][sum+2],i,j;

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

    int mn = 1e18;
    for(i=1; i<=sum; i++)
    {
        if(dp[n][i])
        {
            int x = total - (2*i);
            mn = min(mn,x);
        }
    }

    return mn;
}

void solve()
{
    int n,i;
    cin >> n;
    int arr[n+4];
    for(i=1; i<=n; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }

    cout << MinSum(arr,n,total/2) << endl;
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
5
3 4 8 2 3

Output :
0

Input :
5
1 2 3 4 5

Output :
1

**/
