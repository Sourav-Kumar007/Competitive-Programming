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

void solved(int one,int zero,int n,string op)
{
    if(n==0)
    {
        cout << op << endl;
        return ;
    }

    string op1 = op;
    op1 += '1';
    solved(one+1,zero,n-1,op1);

    if(one>zero)
    {
        string op2 = op;
        op2 += '0';
        solved(one,zero+1,n-1,op2);
    }
    return ;
}

void solve()
{
    int n,one=0,zero=0;
    cin >> n;
    string op;
    solved(one,zero,n,op);
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
4

Output :
1111
1110
1101
1100
1011
1010
**/
