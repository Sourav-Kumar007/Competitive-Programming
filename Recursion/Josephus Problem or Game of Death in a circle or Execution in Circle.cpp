// I write this code by my own. So you can also check Aditya Verma's Implementation
// My Logic :
// At first i started from index 1 and try to find kth valid index from that starting index.
// Let's say starting index is 2 and k==3 so we reach 5 . and now i marked 5th index as true
// It means we have visited 5th index. Then i starting again my function from index 6 recursively for n-1

/**
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh (H S T U).
      Name        : Sourav Roy (Shuvo)
      Department  : Computer Science and Engineering (Batch - CSE'19)
      Email       : souravkumarroy813965@gmail.com
**/


#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define all(a) a.begin(),a.end()
#define pb push_back
#define mod 1000000007
bool marked[100];

int valid(int n,int next)
{
    if(marked[next]==false)
    {
        return next;
    }

    int idx = (next % n) + 1;
    valid(n,idx);
}

int idx(int start,int k,int n)
{
    if(k==1 && marked[start]==false)
    {
        marked[start] = true;
        return start;
    }

    int next = (start % n) + 1;

    if(marked[start])
    {
        idx(next,k,n);
    }
    else
    {
        idx(next,k-1,n);
    }
}

int solved(int n,int k,int start,int total)
{
    if(total==1)
    {
        return start;
    }

    int index = idx(start,k,n);
    int next = (index % n) + 1;
    int valid_next = valid(n,next);

    solved(n,k,valid_next,total-1);
}

void solve()
{
    int n,k,start=1,total;
    cin >> n >> k;
    total = n;
    cout << solved(n,k,start,total) << endl;
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
40 7

Output :
24
**/
