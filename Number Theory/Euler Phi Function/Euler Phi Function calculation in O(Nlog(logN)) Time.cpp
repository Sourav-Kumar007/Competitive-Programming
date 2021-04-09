/// Topic Name      : Euler Phi Function in O(Nlog(logN)) Time (Number Theory part)
/// Time Complexity : O(Nlog(logN))
/// Reference       : CodeNCode YouTube channel
/// Notes           : We can apply Sieve of Eratosthenes algorithm to calculate phi(n) of each number from 1 to n in O(nlog(logn)) time.

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
int phi[1000001];

void init(int maxN)
{
    int i,j;
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

void solve()
{
    int q,n;
    cin >> q;
    while(q--)
    {
        cin >> n;
        cout << phi[n] << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init(1000000);

    int t=1;
    while(t--)
    {
        solve();
    }
}
/**
Test Case :
4
5
10
200
231

Expected output :
4
4
80
121

**/
