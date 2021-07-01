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

void solve()
{
    int n,x,i,j;
    cin >> n >> x;
    vector <int> page(n),price(n);
    for(i=0; i<n; i++)
    {
        cin >> price[i];
    }
    for(i=0; i<n; i++)
    {
        cin >> page[i];
    }

    int dp[n+1][x+1];
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=x; j++)
        {
            dp[i][j] = 0;
        }
    }

    for(i=1; i<=n; i++)
    {
        for(j=0; j<=x; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=price[i-1])
            {
                dp[i][j] = max(dp[i][j],dp[i-1][j-price[i-1]] + page[i-1]);
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
