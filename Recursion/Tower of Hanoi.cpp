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

void solved(int s,int d,int h,int n)
{
    if(n==1)
    {
        cout << "Moving disk " << n << " from " << s << " to " << d << endl;
        return;
    }

    solved(s,h,d,n-1);
    cout << "Moving disk " << n << " from " << s << " to " << d << endl;
    solved(h,d,s,n-1);
    return;
}

void solve()
{
    int n,i;
    cin >> n;
    int s=1;
    int h=2;
    int d=3;

    solved(s,d,h,n);
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
