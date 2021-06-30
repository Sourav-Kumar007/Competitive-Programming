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
int dp[1000005];

int call(int n)
{
    int x = n;
    vector <int> v;
    while(x)
    {
        int d = x%10;
        if(d)
        {
            v.pb(d);
        }
        x/=10;
    }
    if(v.size()==0)
    {
        return 0;
    }
    else
    {
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int mn = 1e18;
        for(int i=0; i<v.size(); i++)
        {
            mn = min(mn,1+call(n-v[i]));
        }
        return dp[n] = mn;
    }
}

void solve()
{
    int n;
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
