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
//#define int long long
#define all(a) a.begin(),a.end()
#define pb push_back
#define mod 1000000007
int dp[105][1000005];

void solve()
{
    int n,i,x,sum;
    cin >> n >> x;
    int coins[n+5];
    for(i=1; i<=n; i++)
    {
        cin >> coins[i];
    }

    for(i=1; i<=n; i++)
    {
        for(sum=0; sum<=x; sum++)
        {
            if(sum==0)
            {
                dp[i][sum] = 1;
            }
            else
            {
                int op1 = (coins[i]>sum)  ? 0 : dp[i][sum-coins[i]];
                int op2 = (i==1) ? 0 : dp[i-1][sum];
                dp[i][sum] = (op1 + op2)%mod;
            }
        }
    }

    cout << dp[n][x] << endl;
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

**/
