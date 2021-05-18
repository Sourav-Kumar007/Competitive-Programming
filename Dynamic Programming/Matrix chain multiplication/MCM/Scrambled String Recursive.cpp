
/*
*
* FILE: C.cpp
*
* Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh (H S T U).
*
* Name        : Sourav Roy (Shuvo)
*
* Department  : Computer Science and Engineering (Batch - CSE'19)
*
* Email       : souravkumarroy813965@gmail.com
*
*/

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define all(a) a.begin(),a.end()
#define pb push_back
#define mod 1000000007

bool call(string a,string b)
{
    if(a==b)
    {
        return true;
    }
    if(a.size()<=1)
    {
        return false;
    }
    int n = a.size(),i;
    bool flag = false;

    for(i=1; i<n; i++)
    {
        if(call(a.substr(0,i),b.substr(0,i)) && call(a.substr(i,n-i),b.substr(i,n-i)))
        {
            flag = true;
            break;
        }
        if(call(a.substr(0,i),b.substr(n-i,i)) && call(a.substr(0,i),b.substr(n-i,i)))
        {
            flag = true;
            break;
        }
    }

    return flag;
}

void solve()
{
    string a,b;
    cin >> a >> b;
    if(a.size()!=b.size())
    {
        cout << "No" << endl;
    }
    else
    {
        if(call(a,b))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
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
Input :
great ategr
Output :
Yes

Input :
great artee
Output :
No
**/
