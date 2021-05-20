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
using namespace std;
#define endl '\n'
#define int long long
#define all(a) a.begin(),a.end()
#define pb push_back
#define mod 1000000007

void heapify(int arr[],int n,int i)
{
    int largest = i;
    int l = 2*i;
    int r = (2*i) + 1;
    if(l<=n && arr[l]>arr[largest])
    {
        largest = l;
    }
    if(r<=n && arr[r]>arr[largest])
    {
        largest = r;
    }
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void solve()
{
    int n,i;
    cin >> n;
    int arr[n+5];
    for(i=1; i<=n; i++)
    {
        cin >> arr[i];
    }

    // For Heap Sort algorithm our first task is to create a Max heap with the help of Heapify

    for(i=n/2; i>=1; i--)
    {
        heapify(arr,n,i);
    }
    for(i=n; i>=1; i--)
    {
        swap(arr[1],arr[i]);
        heapify(arr,i-1,1);
    }
    for(i=1; i<=n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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
5
10 15 5 8 30
**/

