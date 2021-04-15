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

void solved(string ip,string op)
{
    if(ip.length()==0)
    {
        cout << op << endl;
        return;
    }

    string op1 = op;
    string op2 = op;
    op1 += ip[0];
    op2 += toupper(ip[0]);
    ip.erase(0,1);

    solved(ip,op1);
    solved(ip,op2);
    return;
}

void solve()
{
    string ip,op;
    cin >> ip;
    solved(ip,op);
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
abc

Output :
abc
abC
aBc
aBC
Abc
AbC
ABc
ABC

**/
