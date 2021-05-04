// In this problem you are given two string and you have to find whether first string is a subsequence of
// second string or not. To solve this problem you only have to check LCS of two string length is equal to
// the first string or not. because is first string is a subsequence of second string then all the character
// of first string will occur in the same order into second string and then their LCS will equal to the
// first string .

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
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

void solve()
{
    string a,b;
    cin >> a >> b;
    if(LCS(a,b,a.length(),b.length())==a.length())
    {
        cout << "Yes string a is a subsequence of string b" << endl;
    }
    else
    {
        cout << "No" << endl;
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
abc
xcaxxbxcx
Output :
Yes string a is a subsequence of string b

Input :
abc
xcaxxbxx
Output :
No
**/
