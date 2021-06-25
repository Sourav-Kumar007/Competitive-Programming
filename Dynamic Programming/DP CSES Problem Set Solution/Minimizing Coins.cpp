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
int coins[101];
int dp[1000001];

void solve()
{
    int n,x,i,j;
    cin >> n >> x;
    int arr[n+5];
    for(i=1; i<=n; i++)
    {
        cin >> arr[i];
    }
    for(i=1; i<=x; i++)
    {
        dp[i] = 1e18;
    }

    for(i=1; i<=x; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i-arr[j]>=0)
            {
                dp[i] =  min(dp[i],dp[i-arr[j]]+1);
            }
        }
    }

    if(dp[x]==1e18)
    {
        dp[x] = -1;
    }
    cout << dp[x] << endl;
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
