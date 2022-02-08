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
int prefix[200005];

void sparseTable(int n)
{
    int i,j;
    for(i=1; i<=n; i++)
    {
        sparse[i][0] = prefix[i];
    }
    for(j=1; (1<<j)<=n; j++)
    {
        for(i=1; i+(1<<j)-1<=n; i++)
        {
            sparse[i][j] = min(sparse[i][j-1] , sparse[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int l,int r)
{
    int sz = r - l + 1;
    int k = (int)log2(sz);
    return min(sparse[l][k] , sparse[l+sz-(1<<k)][k]);
}

bool isValid(int l,int r,int s)
{
    int x = query(l,r);
    x -= prefix[l - 1];
    //cout << l << " " << r << " " << s << " " << x << endl;
    if(x >= 0)
    {
        return true;
    }
    x *= -1;
    return (s >= x);
}

void solve()
{
    int n,s,i,ans=-1,l,r;
    cin >> n >> s;
    for(i=1; i<=n; i++)
    {
        cin >> arr[i];
        prefix[i] = prefix[i-1] + arr[i];
        //cout << prefix[i] << " ";
    }
    //cout << endl;
    sparseTable(n);

    int start = 1, end = n, mid;
    while(start <= end)
    {
        mid = start + (end - start) / 2;
        int ok = 0;
        for(i=1; i<=n-mid+1; i++)
        {
            if(isValid(i,i+mid-1,s))
            {
                l = i;
                r = i + mid - 1;
                ans = r - l + 1;
                ok = 1;
                break;
            }
        }
        if(ok)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    if(ans==-1)
    {
        cout << ans << endl;
    }
    else
    {
        cout << l << " " << r << endl;
    }
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

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/

