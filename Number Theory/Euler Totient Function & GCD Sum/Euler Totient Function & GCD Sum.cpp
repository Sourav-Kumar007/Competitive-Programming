/// Topic           : ETF & GCD Sum (Number Theory Part)
/// Problem         : You have given q and n. you have to calculate gcd(i,n) for all i from 1 to N for each query
/// Time Complexity : NlogN * (Q * sqrt(N))
/// Reference       : CodeNCode Youtube channel ..https://www.youtube.com/watch?v=miBVc_ySha8&list=PL2q4fbVm1Ik4liHX78IRslXzUr8z5QxsG&index=28


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
#define maxN 1000000
int phi[1000005];

void ETF()
{
    int i,j;
    phi[1] = 1;
    for(i=2; i<=maxN; i++)
    {
        phi[i] = i;
    }

    for(i=2; i<=maxN; i++)
    {
        if(phi[i]==i)
        {
            for(j=i; j<=maxN; j+=i)
            {
                phi[j] /= i;
                phi[j] *= (i-1);
            }
        }
    }
}

int getcount(int d,int n)
{
    return (phi[n/d] * d);
}

void solve()
{
    int q,i,n,d1,d2;
    cin >> q;
    while(q--)
    {
        cin >> n;
        int res = 0;
        for(i=1; i*i<=n; i++)
        {
            if(n%i==0)
            {
                d1 = i;
                d2 = n/i;
                res += getcount(d1,n);
                if(d1!=d2)
                {
                    res += getcount(d2,n);
                }
            }
        }
        cout << res << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ETF();
    int t=1;
    while(t--)
    {
        solve();
    }
}
/**
Test Case :
5
12
15
20
23
28

Expected Output :
40
45
72
45
104

**/
