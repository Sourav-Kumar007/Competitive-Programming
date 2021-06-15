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

void solve()
{
    ordered_set os;
    os.insert(2);
    os.insert(1);
    os.insert(4);
    os.insert(7);
    os.insert(8);

    // In array we can access element by index say arr[x] like this,,but in set we can't.
    // But with the help of policy based data structure we can access the element by index os.find_by_order
    // here the given set is 1 2 4 7 8 so os[2] = 4

    cout << *(os.find_by_order(2)) << endl;

    // we can find the how many numbers are strictly less than x by os.order_of_key

    cout << os.order_of_key(7) << endl;

    // os.order_of_key(x) returns how many numbers there are which are strictly less than x
    // os.order_of_key(7) will output 3 because 3 numbers 1,2,4 are strictly less than 7
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
