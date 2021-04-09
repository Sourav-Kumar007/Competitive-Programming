/// Topic : Binomial Coefficient Using Modulo Inverse. (Number Theory)
/// Reference : CodeNCode (YouTube Channel)
/// Time Complexity : O(N * logN)
/// Prerequisite : Inverse Modulo,Fast Exponentiation .


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
int F[1000001];

int power(int base,int pow)
{
    int res = 1;
    while(pow)
    {
        if(pow&1)
        {
            res = (res * 1LL * base) % mod;
            pow--;
        }
        else
        {
            base = (base * 1LL * base) % mod;
            pow /= 2;
        }
    }
    return res;
}

int C(int n,int k)
{
    if(k>n)
    {
        return 0;
    }

    int res = F[n];
    res = (res * 1LL * power(F[k],mod-2)) % mod;
    res = (res * 1LL * power(F[n-k],mod-2)) % mod;

    return res;
}

void solve()
{
    F[0]=F[1]=1;
    int i,q,n,k;
    for(i=2; i<=1000000; i++)
    {
        F[i] = (F[i-1] * 1LL * i) % mod;
    }

    cin >> q;
    while(q--)
    {
        cin >> n >> k;
        cout << C(n,k) << endl;
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
5
5 7
5 5
5 2
10 3
1000 500
ans :
0
1
10
120
159835829
**/
