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

int solved(int n,int k)
{
    if(n==1 && k==1)
    {
        return 0;
    }

    int mid = (int)pow(2,n-1) / 2;
    if(k<=mid)
    {
        return solved(n-1,k);
    }
    else
    {
        return !solved(n-1,k-mid);
    }
}

void solve()
{
    int n,k,i;
    cin >> n >> k;
    cout << solved(n,k) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
/**
Test Case :
8
4 1
4 2
4 3
4 4
4 5
4 6
4 7
4 8
**/
