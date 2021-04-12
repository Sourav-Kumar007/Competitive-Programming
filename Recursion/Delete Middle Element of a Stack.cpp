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

void sol(stack <int> &s,int k)
{
    if(k==1)
    {
        s.pop();
        return;
    }

    int temp = s.top();
    s.pop();

    sol(s,k-1);

    s.push(temp);
    return;
}

middelete(stack <int> &s,int n)
{
    int k = n/2 + 1;
    sol(s,k);
}

void solve()
{
    stack <int> s,t;
    int n,i,x;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> x;
        s.push(x);
    }

    middelete(s,n);

    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
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

**/

