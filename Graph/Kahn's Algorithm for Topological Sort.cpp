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
int in[100];
vector <int> arr[100];
vector <int> ans;

void kahn(int n)
{
    queue <int> q;
    for(int i=1; i<=n; i++)
    {
        if(in[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int node = q.front();
        ans.pb(node);
        q.pop();
        for(int child : arr[node])
        {
            in[child]--;
            if(in[child] == 0)
            {
                q.push(child);
            }
        }
    }

    cout << "TopSort : " ;
    for(auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}

void solve()
{
    int n,m,a,b,i;
    cin >> n >> m;
    for(i=1; i<=m; i++)
    {
        cin >> a >> b;
        arr[a].pb(b);
        in[b]++;
    }

    kahn(n);

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
Input :
9 10
1 2
3 4
1 8
2 9
2 5
4 5
4 8
5 9
5 7
6 7
Output :
TopSort : 1 3 6 2 4 5 8 9 7
**/

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/

