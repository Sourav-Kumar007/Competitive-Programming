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
#define mod 998244353
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
int fact[400000];

void corona()
{
    fact[0] = 1;
    for(int i=1; i<=3e5+10; i++)
    {
        fact[i] = (fact[i-1] * 1LL * i) % mod;
    }
}

int binpow(int base,int pow)
{
    int res = 1;
    while(pow)
    {
        if(pow&1)
        {
            res = (res * 1LL * base) % mod;
            pow--;
        }
        else
        {
            base = (base * 1LL * base) % mod;
            pow /= 2;
        }
    }
    return res;
}

int ncr(int n,int r)
{
    if(r > n)
    {
        return 0;
    }
    if(r == n)
    {
        return 1;
    }
    int res = fact[n];
    res = (res * 1LL * binpow(fact[n-r], mod-2)) % mod;
    res = (res * 1LL * binpow(fact[r], mod-2)) % mod;
    return res;
}

void solve()
{
    int n,k,l,r,last=-1,i,ans=0,j;
    cin >> n >> k;
    vector <pair <int,int> > v;
    map <int,int> mp;
    for(i=1; i<=n; i++)
    {
        cin >> l >> r;
        mp[l]++;
        v.pb({l,r});
    }
    sort(all(v));

    priority_queue <int,vector <int>, greater<int> > q;
    for(i=0; i<n; i++)
    {
        if(v[i].first != last)
        {
            while(!q.empty())
            {
                if(q.top() >= v[i].first)
                {
                    break;
                }
                q.pop();
            }
            int option = mp[v[i].first];
            for(j=1; j<=min(k,option); j++)
            {
                ans = (ans + (ncr(option, j) * ncr(q.size(), k - j)) % mod) % mod;
            }
        }
        q.push(v[i].second);
        last = v[i].first;
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    corona();
    int t=1;
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
