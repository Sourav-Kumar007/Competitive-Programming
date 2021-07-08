// You are given some coins and a sum you have to print a subset which sum is equal to the intial given sum.
// Time Complexity  : O(N*M) , Here N is the number of coins and M is the total sum.
// Space Complexity : O(M)

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

void solve()
{
    int n,sum,i,j;
    cin >> n >> sum;
    int coins[n+1];
    for(i=1; i<=n; i++)
    {
        cin >> coins[i];
    }

    int dp[sum+1];
    dp[0] = 1;
    for(i=1; i<=sum; i++)
    {
        dp[i] = 0;
    }
    for(i=1; i<=n; i++)
    {
        for(j=sum; j>=coins[i]; j--)
        {
            if(dp[j] || (dp[j-coins[i]]==0))
            {
                continue;
            }
            dp[j] = coins[i];
        }
    }


    if(dp[sum]==0)
    {
        cout << - 1 << endl;
    }
    else
    {
        int curr = sum;
        while(curr>0)
        {
            cout << dp[curr] << " ";
            curr -= dp[curr];
        }
        cout << endl;
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
4 11
2 5 3 4
**/
