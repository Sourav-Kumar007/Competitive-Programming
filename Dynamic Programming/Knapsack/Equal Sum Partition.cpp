// In this problem you are given an array and you have to find whether it is possible to divide the whole array
// into two part such that the sum of each part is equal to each other. To solve this problem we use the previous
// Subset sub problem. But why? Let's see. If total sum of the array is odd then there is no way to divide it into
// two equal sum partition. But when it is even there is chance. So when total sum will be even we will try to find
// out whether it is possible to get subset sum equal to the half of that total sum. Let's assume it is possible
// then you can always find such two part which sum is equal .


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
int arr[1000],dp[2002][2002];

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

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=sum; j++)
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
    int n,i,sum=0;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    if(sum&1)
    {
        cout << "No" << endl;
    }
    else
    {
        if(SubSet(n,sum))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
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
6
2 3 3 4 8 2

Output :
Yes
**/
