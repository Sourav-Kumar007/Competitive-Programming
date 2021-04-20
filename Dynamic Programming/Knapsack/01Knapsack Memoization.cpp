// For this problem at first i write recursive code and then memorize some result for n and w.Then this
// recursive solution turn into DP solution. We just took decision for every element where we took this
// to bad or not. We started from end of the array. At first we took decision for nth element. and then
// we call this knapsack function again for smaller input .

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
int dp[102][1002];

int knapsack(int weight[],int price[],int w,int n)
{
    if(n==0 || w==0)
    {
        return 0;
    }

    if(dp[n][w]!=-1)
    {
        return dp[n][w];
    }

    if(weight[n]<=w)
    {
        dp[n][w] = max(price[n]+knapsack(weight,price,w-weight[n],n-1),knapsack(weight,price,w,n-1));
        return dp[n][w];
    }
    else
    {
        dp[n][w] = knapsack(weight,price,w,n-1);
        return dp[n][w];
    }
}
void solve()
{
    int n,w,i;
    cin >> n >> w;
    int weight[n+4],price[n+4];

    memset(dp,-1,sizeof(dp));

    for(i=1; i<=n; i++)
    {
        cin >> weight[i];
    }
    for(i=1; i<=n; i++)
    {
        cin >> price[i];
    }

    cout << knapsack(weight,price,w,n) << endl;
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
6 21
133 5 77 10 155 4
3 10 4 8 1 7

Output :
25
**/
