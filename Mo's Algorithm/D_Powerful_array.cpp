//https://codeforces.com/contest/86/problem/D
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
#define block 555

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
struct query
{
    int l,r,i;
};
query Q[200001];
int arr[200001],ans[200001],freq[2000001],power;

bool cmp(query a,query b)
{
    if(a.l/block != b.l/block)
    {
        return a.l/block < b.l/block;
    }
    return a.r < b.r;
}

void add(int pos)
{
    int cnt = freq[arr[pos]];
    freq[arr[pos]]++;
    power -= (cnt * cnt * arr[pos]);
    cnt++;
    power += (cnt * cnt * arr[pos]);
}

void remove(int pos)
{
    int cnt = freq[arr[pos]];
    freq[arr[pos]]--;
    power -= (cnt * cnt * arr[pos]);
    cnt--;
    power += (cnt * cnt * arr[pos]);
}

void solve()
{
    int n,q,i;
    cin >> n >> q;
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    for(i=0; i<q; i++)
    {
        cin >> Q[i].l >> Q[i].r;
        Q[i].i = i;
        Q[i].l--;
        Q[i].r--;
    }
    sort(Q , Q+q , cmp);
    int cL = 0,cR = -1;
    for(i=0; i<q; i++)
    {
        int L = Q[i].l;
        int R = Q[i].r;

        while(cL > L)
        {
            cL--;
            add(cL);
        }

        while(cR < R)
        {
            cR++;
            add(cR);
        }

        while(cL < L)
        {
            remove(cL);
            cL++;
        }

        while(cR > R)
        {
            remove(cR);
            cR--;
        }

        ans[Q[i].i] = power;
    }

    for(i=0; i<q; i++)
    {
        cout << ans[i] << endl;
    }
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1;
    while(t--)
    {
        solve();
    }
}
/**
Test Case :
 
**/