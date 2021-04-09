/// Topic           : Fermat Primality Test (Number Theory Part)
/// Time Complexity : O(Q * logN) -> Q stands for query and N is the number
/// Reference       : CodeNCode Youtube Channel
/// Link            : https://www.youtube.com/watch?v=LR0986Y32iI&list=PL2q4fbVm1Ik4liHX78IRslXzUr8z5QxsG&index=35


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

int mulmod(int a,int b,int c)
{
    int res=0;
    int y=a%c;
    while(b)
    {
        if(b&1)
        {
            res = (res + y) % c;
            b--;
        }
        else
        {
            y = (y * 2LL) % c;
            b/=2;
        }
    }
    return res;
}

int binpower(int base,int pow,int m)
{
    int res = 1;
    while(pow)
    {
        if(pow&1)
        {
            res = mulmod(res,base,m);
            pow--;
        }
        else
        {
            base = mulmod(base,base,m);
            pow/=2;
        }
    }
    return res;
}

bool isprime(int n,int iterations = 5)
{
    if(n<=4)
    {
        return (n==2 || n==3);
    }

    for(int i=1; i<=iterations; i++)
    {
        int a = 2 + rand() % (n-3);
        if(binpower(a,n-1,n) != 1)
        {
            return false;
        }
    }

    return true;
}

void solve()
{
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        if(isprime(n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
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
103
1234
10000007
1000000007
3588

Expected Output :
YES
NO
NO
YES
NO
**/
