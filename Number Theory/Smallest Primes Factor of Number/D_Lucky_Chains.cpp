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
#define inf 1e18
#define ppb pop_back
#define ff first
#define ss second
 
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
 
#define debug(x); cerr << #x <<" "; _print(x); cerr << endl;
 
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
int sf[10000007];

void corona()
{
    for(int i=2; i<=10000000; i++)
    {
        if(!sf[i])
        {
            sf[i] = i;
            for(int j=i*i; j<=10000000; j+=i)
            {
                sf[j] = i;
            }
        }
    }
}

void solve()
{
    int x,y;
    cin >> x >> y;
    if(y - x == 1)
    {
        cout << -1 << endl;
    }
    else if(__gcd(x , y) > 1)
    {
        cout << 0 << endl;
    }
    else 
    {
        int n = y - x;
        vector <int> v;
        while(n > 1)
        {
            int di = sf[n];
            v.pb(di);
            while(n % di == 0)
            {
                n /= di;
            }
        }
        int ans = inf;
        for(auto it : v)
        {
            ans = min(ans , it - (x % it));
        }
        cout << ans << endl;
    }
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