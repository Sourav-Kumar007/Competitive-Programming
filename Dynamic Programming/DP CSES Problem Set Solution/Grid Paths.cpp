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
int dp[1001][1001];
char arr[1001][1001];
int n;

int call(int row,int col)
{
    if(row==n)
    {
        int ok = 1;
        for(int i = col; i<=n; i++)
        {
            if(arr[row][i]=='*')
            {
                ok = 0;
                break;
            }
        }
        if(ok)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(dp[row][col]!=-1)
    {
        return dp[row][col];
    }
    if(col==n)
    {
        if(arr[row+1][col]!='*')
        {
            return dp[row][col] = call(row+1,col)%mod;
        }
        else
        {
            return dp[row][col] = 0;
        }
    }
    else
    {
        int op1,op2;
        op1 = op2 = 0;
        if(arr[row+1][col]!='*')
        {
            op1 = call(row+1,col);
        }
        if(arr[row][col+1]!='*')
        {
            op2 = call(row,col+1);
        }
        return dp[row][col] = (op1%mod + op2%mod)%mod;
    }
}

void solve()
{
    int i,j;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cin >> arr[i][j];
        }
    }
    if(arr[1][1]=='*')
    {
        cout << 0 << endl;
    }
    else
    {
        memset(dp,-1,sizeof(dp));
        cout << call(1,1) << endl;
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

**/
