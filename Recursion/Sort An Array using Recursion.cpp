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

void inserT(vector <int> &v,int temp)
{
    if(v.size()==0 || v[v.size()-1]<=temp)
    {
        v.pb(temp);
        return ;
    }

    int val = v.back();
    v.pop_back();

    inserT(v,temp);
    v.pb(val);

    return ;
}

void sorT(vector <int> &v)
{
    if(v.size()==1)
    {
        return ;
    }

    int temp = v.back();
    v.pop_back();

    sorT(v);
    inserT(v,temp);
}



void solve()
{
    int n,i,x;
    cin >> n;
    vector <int> v;

    for(i=1; i<=n; i++)
    {
        cin >> x;
        v.pb(x);
    }

    sorT(v);

    for(auto it : v)
    {
        cout << it << " ";
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
