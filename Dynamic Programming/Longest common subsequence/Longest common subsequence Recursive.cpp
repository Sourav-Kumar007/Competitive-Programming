// “Success is not final, failure is not fatal: it is the courage to continue that counts.” — Winston Churchill

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

int LCS(string s,string t,int n,int m)
{
    if(n==0 || m==0)
    {
        return 0;
    }

    if(s[n-1]==t[m-1])
    {
        return 1 + LCS(s,t,n-1,m-1);
    }
    else
    {
        return max(LCS(s,t,n-1,m),LCS(s,t,n,m-1));
    }
}

void solve()
{
    int n,m;
    string s,t;

    cin >> n >> m >> s >> t;

    cout << LCS(s,t,n,m) << endl;
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
9 6
acbfeghmm
abedml

Output :
4

Input :
9 15
aeflfnrtx
bmbbefgqqnpruux

Output :
5
**/
