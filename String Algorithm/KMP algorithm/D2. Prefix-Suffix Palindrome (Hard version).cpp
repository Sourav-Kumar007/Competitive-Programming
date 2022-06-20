///    Success is not a Miracle , it's a journey of DEDICATION   ///

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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define int long long
#define all(a) a.begin(),a.end()
#define pb push_back
#define mod 1000000007
#define inf 1e18+7
///  order_of_key return number of elements less than x -> os.order_of_key(x)
///  cout << "oth element  : " << *os.find_by_order(0) << endl; so it returns value of index
int lcm(int x,int y)
{
    return (x * 1LL * y) / __gcd(x,y);
}

// Graph on 2D Grid
/*----------------------Graph Moves----------------*/
//const int dx[]={+1,-1,+0,+0};
//const int dy[]={+0,+0,+1,-1};
//const int dx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int dy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int dx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int dy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

int kmp(string s)
{
	vector<int> lps(s.size(), 0);

	for (int i = 1; i < (int)lps.size(); ++i)
	{
		int prev_idx = lps[i - 1];

		while (prev_idx > 0 && s[i] != s[prev_idx])
		{
			prev_idx = lps[prev_idx - 1];
		}

		lps[i] = prev_idx + (s[i] == s[prev_idx] ? 1 : 0);
	}

	return lps[lps.size() - 1];
}

int longest_palindrome(string t)
{
    string s = t + '?';
    reverse(all(t));
    s += t;
    return kmp(s);
}

void solve()
{
    string s;
    cin >> s;
    int n = s.length(),i,l=0,j;
    for(l=0,j=n-1; l<j; l++,j--)
    {
        if(s[l] != s[j])
        {
            break;
        }
    }

    string ans,rem;
    ans = s.substr(0 , l);
    rem = s.substr(l , n - (l + l));
    if(rem.size())
    {
        int n1 = longest_palindrome(rem);
        string s1 = rem.substr(0 , n1);
        reverse(all(rem));
        int n2 = longest_palindrome(rem);
        string s2 = rem.substr(0 , n2);
        if(n1 >= n2)
        {
            ans += s1;
        }
        else
        {
            ans += s2;
        }
    }
    ans += s.substr(n-l , l);

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
/**
Test Case :

**/
///  stuck in finding min / max problem ? think for binary search
///  special case : n = 1 ?
///  try to think in a different way or take a brake from pc and walk away
/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/

