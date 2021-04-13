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

void Insert(stack <int> &s,int temp)
{
    if(s.size()==0)
    {
        s.push(temp);
        return ;
    }

    int value = s.top();
    s.pop();
    Insert(s,temp);
    s.push(value);
    return ;
}

void Reverse(stack <int> &s)
{
    if(s.size()==1)
    {
        return ;
    }

    int temp = s.top();
    s.pop();
    Reverse(s);
    Insert(s,temp);
    return ;
}

void solve()
{
    int n,i,x;
    cin >> n;
    stack <int> s,t;
    for(i=1; i<=n; i++)
    {
        cin >> x;
        t.push(x);
        s.push(x);
    }

    cout << "Before Reverse : " << endl;
    while(!t.empty())
    {
        cout << t.top() << " ";
        t.pop();
        cout << endl;
    }
    cout << endl;

    Reverse(s);

    cout << "After Reverse : " << endl;
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
        cout << endl;
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
1 2 3 4 5
**/
