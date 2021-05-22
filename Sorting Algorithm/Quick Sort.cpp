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
int n;

int partition(int arr[],int l,int h)
{
    int i = l;
    int j = h;
    int pivot = arr[l];

    while(i<j)
    {
        while(i<=h && arr[i]<=pivot)
        {
            i++;
        }

        while(j>0 && arr[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[l],arr[j]);
    return j;
}

void quicksort(int arr[],int l,int h)
{
    int j;
    if(l<h)
    {
        j = partition(arr,l,h);
        quicksort(arr,l,j-1);
        quicksort(arr,j+1,h);
    }
}

void solve()
{
    int i;
    cin >> n;
    int arr[n+5];
    for(i=1; i<=n; i++)
    {
        cin >> arr[i];
    }
    quicksort(arr,1,n);
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
9
10 16 8 12 15 6 3 9 5

5
5 4 3 2 1
**/
