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
int dp[2000000];

int call(int n)
{
    if(n==1 || n==0)
    {
        return 1;
    }
    int i,ans=0,six=6;
    for(i=1; i<=min(six,n); i++)
    {
        int x;
        if(dp[n-i]!=-1)
        {
            x = dp[n-i];
        }
        else
        {
            x = call(n-i);
            dp[n-i] = x;
        }
        ans = (ans%mod + x%mod)%mod;
    }
    return ans;
}

void solve()
{
    int n,i;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    cout << call(n) << endl;
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
