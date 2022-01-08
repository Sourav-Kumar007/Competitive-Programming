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
    int n,i,k,x;
    cin >> n >> k;
    char ch;
    int arr[n+5];
    memset(parent,-1,sizeof(parent));
    for(i=1; i<=n; i++)
    {
        cin >> ch;
        arr[i] = ch - '0';
    }

    int par = -1,cnt=0,mn=0;
    for(i=1; i<=n; i++)
    {
        if(arr[i] && par==-1)
        {
            par = i;
            cnt = 1;
        }
        else if(arr[i] && par!=-1)
        {
            cnt++;
            parent[par] = -1 * cnt;
            parent[i] = par;
        }
        else
        {
            cnt = 0;
            par = -1;
        }
    }

    for(i=1; i<=n; i++)
    {
        if(arr[i])
        {
            mn = min(mn,parent[i]);
        }
    }


    for(i=1; i<=k; i++)
    {
        int type;
        cin >> type;
        if(type==1)
        {
            cout << abs(mn) << endl;
        }
        else
        {
            cin >>x;
            if(arr[x])
            {
                continue;
            }
            else
            {
                arr[x] = 1;
                int ok = 0;
                if(x+1<=n && arr[x+1])
                {
                    int par1 = finds(x+1);
                    ok++;
                    int par2 = finds(x);
                    uni(par1,par2);
                    mn = min(mn,parent[par1]);
                }
                if(x-1>=1 && arr[x-1])
                {
                    int par1 = finds(x-1);
                    ok++;
                    int par2 = finds(x);
                    uni(par1,par2);
                    mn = min(mn,parent[par1]);
                }
                if(ok==0)
                {
                    mn = min(mn,parent[i]);
                }
            }
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
10 5
0110111001
1
2 8
1
2 9
1
**/

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/

