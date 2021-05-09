// In this problem you are given an string and you have to tell minimum number of partition to divide the
// string and each of the string will be palindrome. ex : nitikror .. ans will 3 because you can create substring
// n iti k ror by 3 partition and all of them are palindrome.

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

bool isPalindrome(string s,int i,int j)
{
    if(i>j)
    {
        return false;
    }
    if(i==j)
    {
        return true;
    }

    while(i<j)
    {
        if(s[i]!=s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int partition(string s,int i,int j)
{
    if(i>=j)
    {
        return 0;
    }

    if(isPalindrome(s,i,j))
    {
        return 0;
    }
    int mn = 1e18,k;

    for(k=i; k<j; k++)
    {
        int temp = 1 + partition(s,i,k) + partition(s,k+1,j);
        mn = min(mn,temp);
    }
    return mn;
}

void solve()
{
    string s;
    cin >> s;
    cout << partition(s,0,s.size()-1) << endl;
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
nitikror
Output :
3
**/
