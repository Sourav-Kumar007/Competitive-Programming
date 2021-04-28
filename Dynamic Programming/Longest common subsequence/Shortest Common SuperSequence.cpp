// In this problem you are given two string and you have to output a shortest possible string which subsequence
// will be that given two string. that means you are given geek and eke so if you output geeke.this string will
// contain geek and eke as a subsequence.

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

void SuperSequence(string s,string t,int n,int m)
{
    int dp[n+1][m+1],i,j;

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=m; j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    string ans;
    vector <int> ss,tt;
    i = n;
    j = m;

    while(i && j)
    {
        if(s[i-1]==t[j-1])
        {
            ss.pb(i-1);
            tt.pb(j-1);
            i--;
            j--;
        }
        else
        {
            if(dp[i][j-1]<dp[i-1][j])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    reverse(all(ss));
    reverse(all(tt));

    int ids = -1,idt = -1;

    for(i=0; i<ss.size(); i++)
    {
        for(j=ss[i]-1; j>ids; j--)
        {
            ans += s[j];
        }
        for(j=tt[i]-1; j>idt; j--)
        {
            ans += t[j];
        }
        ans += s[ss[i]];
        ids = ss[i];
        idt = tt[i];
    }


    for(i=s.size()-1; i>ids; i--)
    {
        ans += s[i];
    }
    for(i=t.size()-1; i>idt; i--)
    {
        ans += t[i];
    }

    cout << ans << endl;
}

void solve()
{
    string s,t;
    cin >> s >> t;
    SuperSequence(s,t,s.length(),t.length());
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
geek
eke
Output :
egeke

Input :
axxmryi
dadmdri
Output :
daxxdmdryi
**/
