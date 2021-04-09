/// Topic           :  Calculating Euler's Totient Function in O(sqrt(N)) (Number Theory Part)
/// Time Complexity :  O(sqrt(N))
/// Reference       :  CodeNCode YouTube channel
/// Notes           :  phi(n) = (n * (p1-1) * (p2-1) * (p3-1) * (pk-1)) / (p1 * p2 * p3 * pk) [here, p1,p2,p3,...pk are prime numbers]


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

int phi(int n)
{
    int i,res=n;

    for(i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            res /= i;
            res *= (i-1);
            while(n%i==0)
            {
                n /= i;
            }
        }
    }

    if(n>1)
    {
        res /= n;
        res *= (n-1);
    }

    return res;
}

void solve()
{
    int n;
    cin >> n;
    cout << "ETF(" << n << ") = " << phi(n) << endl;
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
4
30
200
500
497

Expected Output :
ETF(30) = 8
ETF(200) = 80
ETF(500) = 200
ETF(497) = 420
**/

