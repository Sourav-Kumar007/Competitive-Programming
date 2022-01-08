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
int parent[100005];

int finds(int a)
{
    if(parent[a]<0)
    {
        return a;
    }
    return parent[a] = finds(parent[a]);
}

void uni(int a,int b)
{
    parent[a] += parent[b];
    parent[b] = a;
}

void solve()
{
    int n,i,m,a,b,cc;
    cin >> n >> m;
    memset(parent,-1,sizeof(parent));
    int mn = -1;
    cc = n;
    for(i=1; i<=m; i++)
    {
        cin >> a >> b;
        int par1 = finds(a);
        int par2 = finds(b);
        if(par1==par2)
        {
            cout << cc << " " << abs(mn) << endl;
        }
        else
        {
            uni(par1,par2);
            mn = min(mn,parent[par1]);
            cc--;
            cout << cc << " " << abs(mn) << endl;
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

**/

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/

