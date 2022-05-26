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
int arr[200005],st[800005],lazy[800005];

void buildtree(int si,int ss,int se)
{
    if(ss == se)
    {
        st[si] = arr[ss];
        return ;
    }

    int mid = (ss + se) / 2;
    buildtree(2*si , ss , mid);
    buildtree(2*si+1 , mid+1 , se);
    st[si] = st[2*si] + st[2*si+1];
}

int query(int si,int ss,int se,int qs,int qe)
{
    if(lazy[si] != 0)
    {
        int dx = lazy[si];
        lazy[si] = 0;
        st[si] += dx * (se - ss + 1);

        if(ss != se)
        {
            lazy[2*si] += dx;
            lazy[2*si+1] += dx;
        }
    }

    if(ss > qe || se < qs)
    {
        return 0;
    }

    if(ss >= qs && se <= qe)
    {
        return st[si];
    }

    int mid = (ss + se) / 2;
    return query(2*si , ss , mid , qs , qe) + query(2*si+1 , mid+1 , se , qs , qe);
}

void update(int si,int ss,int se,int qs,int qe,int val)
{
    if(lazy[si] != 0)
    {
        int dx = lazy[si];
        lazy[si] = 0;
        st[si] += dx * (se - ss + 1);

        if(ss != se)
        {
            lazy[2*si] += dx;
            lazy[2*si+1] += dx;
        }
    }

    if(ss > qe || se < qs)
    {
        return;
    }

    if(ss >= qs && se <= qe)
    {
        int dx = (se - ss + 1) * val;
        st[si] += dx;

        if(ss != se)
        {
            lazy[2*si] += val;
            lazy[2*si+1] += val;
        }
        return ;
    }

    int mid = (ss + se) / 2;
    update(2*si , ss , mid , qs , qe , val);
    update(2*si+1 , mid+1 , se , qs , qe , val);
    st[si] = st[2*si] + st[2*si+1];
}

void solve()
{
    int n,q,i,t,l,r,x;
    cin >> n >> q;
    for(i=1; i<=n; i++)
    {
        cin >> arr[i];
    }
    buildtree(1 , 1 , n);

    while(q--)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> l >> r >> x;
            update(1 , 1 , n , l , r , x);
        }
        else
        {
            cin >> l >> r;
            cout << query(1 , 1 , n , l , r) << endl;
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
7 9
1 2 3 4 5 6 7
1 2 5 3
2 2 5
2 1 1
2 2 2
2 3 3
2 4 4
2 5 5
2 6 6
2 7 7
**/
///  stuck in finding min / max problem ? think for binary search
///  special case : n = 1 ?
///  try to think in a different way or take a brake from pc and walk away
/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/

