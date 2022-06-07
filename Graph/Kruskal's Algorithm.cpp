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
vector <pair <int,pair <int,int> > > v;
int parent[1001];

int finds(int p)
{
    if(parent[p] < 0)
    {
        return p;
    }
    return parent[p] = finds(parent[p]);
}

void uni(int a,int b)
{
    parent[a] += parent[b];
    parent[b] = a;
}

void solve()
{
    int n,m,i,a,b,w,ans=0;
    cin >> n >> m;
    while(m--)
    {
        cin >> a >> b >> w;
        v.pb(make_pair(w,make_pair(a,b)));
    }
    sort(all(v));

    memset(parent,-1,sizeof(parent));
    for(auto it : v)
    {
        int a = it.second.first;
        int b = it.second.second;
        int p1 = finds(a);
        int p2 = finds(b);
        if(p1 != p2)
        {
            ans += it.first;
            uni(p1 , p2);
        }
    }

    cout << ans << endl;
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
6 9
1 4 1
1 2 2
2 3 3
2 4 3
1 5 4
3 4 5
2 6 7
3 6 8
4 5 9
**/
///  stuck in finding min / max problem ? think for binary search
///  special case : n = 1 ?
///  try to think in a different way or take a brake from pc and walk away
/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/

