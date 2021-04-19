// This is very Famous well known Problem.
// In this problem you are given a bag and weight capacity of bag. You have to put some weight in such a way such that
// price would be maximum possible.


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

int knapsack(int wt[],int pr[],int w,int n)
{
    if(n==0 || w==0)
    {
        return 0;
    }

    if(wt[n]<=w)
    {
        return max(pr[n]+knapsack(wt,pr,w-wt[n],n-1),knapsack(wt,pr,w,n-1));
    }
    else
    {
        return knapsack(wt,pr,w,n-1);
    }
}

void solve()
{
    int n,i,w;
    cin >> n >> w;
    int wt[n+4],pr[n+4];

    for(i=1; i<=n; i++)
    {
        cin >> wt[i];
    }
    for(i=1; i<=n; i++)
    {
        cin >> pr[i];
    }

    cout << knapsack(wt,pr,w,n) << endl;
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
5 20
20 5 12 3 5

Output :
10 10 10 10 9

Input :
5 20
20 5 12 3 5

Output :
10 1 1 1 12
**/
