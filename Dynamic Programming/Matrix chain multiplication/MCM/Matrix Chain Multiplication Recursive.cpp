// It is a very standard DP problem. In this problem you are given matrix dimension and you have find minimum
// number of multiplication cost.

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

int Matrixchain(int arr[],int i,int j)
{
    if(i>=j)
    {
        return 0;
    }

    int mn = INT_MAX,k;
    for(k=i; k<j; k++)
    {
        int res = Matrixchain(arr,i,k) + Matrixchain(arr,k+1,j) + (arr[i-1] * arr[k] * arr[j]);
        mn = min(mn,res);
    }

    return mn;
}

void solve()
{
    int n,i;
    cin >> n;
    int arr[n+4];
    for(i=0; i<=n; i++)
    {
        cin >> arr[i];
    }

    cout << Matrixchain(arr,1,n) << endl;
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
5
10 20 30 25 40 20 60
Output :
31500
**/
