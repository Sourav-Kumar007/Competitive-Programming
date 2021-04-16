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

void solved(int open,int close,string op)
{
    if(open==0 && close==0)
    {
        cout << op << endl;
        return ;
    }

    if(open)
    {
        string op1 = op;
        op1 += '(';
        solved(open-1,close,op1);
    }
    if(close>open)
    {
        string op2 = op;
        op2 += ')';
        solved(open,close-1,op2);
        return ;
    }
}

void solve()
{
    int n,open,close;
    cin >> n;
    string op;
    open = close = n;
    solved(open,close,op);
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
3

Output :
((()))
(()())
(())()
()(())
()()()
**/
