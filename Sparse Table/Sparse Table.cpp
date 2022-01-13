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

// Graph on 2D Grid
/*----------------------Graph Moves----------------*/
//const int dx[]={+1,-1,+0,+0};
//const int dy[]={+0,+0,+1,-1};
//const int dx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int dy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int dx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int dy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/
int arr[200005];
int sparse[200005][32];

void SparseTable(int n)
{
    int i,j;
    for(i=1; i<=n; i++)
    {
        sparse[i][0] = arr[i];
    }
    for(j=1; (int)pow(2,j)<=n; j++)
    {
        for(i=1; i+(int)pow(2,j)-1<=n; i++)
        {
            sparse[i][j] = min(sparse[i][j-1] , sparse[i+(int)pow(2,j-1)][j-1]);
        }
    }
}

int query(int low,int high)
{
    int l = high - low + 1;
    int k = (int)log2(l);
    return min(sparse[low][k] , sparse[low+l-(int)pow(2,k)][k]);
}

void solve()
{
    int n,i,j,q,l,r;
    cin >> n >> q;
    for(i=1; i<=n; i++)
    {
        cin >> arr[i];
    }

    SparseTable(n);

    while(q--)
    {
        cin >> l >> r;
        cout << query(l,r) << endl;
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
6 3
4 5 8 2 6 3
1 3
4 6
2 5
**/

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/

