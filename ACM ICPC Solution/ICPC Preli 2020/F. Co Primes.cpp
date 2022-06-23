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
vector <int> v;
bool marked[10000005];
int mx = 1e7,q=1;

void corona()
{
    int i,j;
    for(i=3; i*i<=mx; i+=2)
    {
        if(marked[i] == false)
        {
            for(j=i*i; j<=mx; j+=i+i)
            {
                marked[j] = true;
            }
        }
    }
    v.pb(2);
    for(i=3; i<=mx; i+=2)
    {
        if(marked[i] == false)
        {
            v.pb(i);
        }
    }
}

int F(int n,int x)
{
    vector <int> primes;
    for(int i=0; v[i] * v[i]<=x; i++)
    {
        int cnt = 0;
        while(x % v[i] == 0)
        {
            cnt++;
            x /= v[i];
        }
        if(cnt)
        {
            primes.pb(v[i]);
        }
    }
    if(x > 1)
    {
        primes.pb(x);
    }
    int ans = 0;
    for(int mask = 1; mask < (1<<primes.size()); mask++)
    {
        int cnt = 0,res = 1;
        for(int i=0; i<primes.size(); i++)
        {
            if(mask&(1<<i))
            {
                cnt++;
                res *= primes[i];
            }
        }
        if(cnt&1)
        {
            ans += (n / res);
        }
        else
        {
            ans -= (n / res);
        }
    }
    return n - ans;
}

void solve()
{
    int a,b,m,i,ans = 0,x,j;
    cin >> a >> b >> m;
    if(a > b)
    {
        swap(a , b);
    }

    if(a == b)
    {
        if(a == 1)
        {
            cout << "Case " << q << ": " << 1 << endl;
        }
        else
        {
            cout << "Case " << q << ": " << 0 << endl;
        }
        q++;
        return ;
    }
    cout << "Case " << q << ": " << F(a+m , b-a) - F(a-1 , b-a) << endl;
    q++;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    corona();
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

