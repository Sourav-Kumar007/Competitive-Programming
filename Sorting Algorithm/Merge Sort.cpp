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

void merge(int arr[],int l,int mid,int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int L[n1+5];
    int R[n2+5];
    int i,j,k=l;

    for(i=1; i<=n1; i++)
    {
        L[i] = arr[k];
        k++;
    }
    for(i=1; i<=n2; i++)
    {
        R[i] = arr[k];
        k++;
    }
    k=l;

    i=j=1;
    while(i<=n1 && j<=n2)
    {
        if(L[i]<=R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    if(i>n1)
    {
        while(j<=n2)
        {
            arr[k] = R[j];
            k++;
            j++;
        }
    }
    else
    {
        while(i<=n1)
        {
            arr[k] = L[i];
            k++;
            i++;
        }
    }
}

void mergesort(int arr[],int l,int r)
{
    if(l>=r)
    {
        return ;
    }
    int mid = l + (r-l)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
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
    mergesort(arr,1,n);
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
Input :
7
3 6 5 1 9 5 4
Output :
1 3 4 5 5 6 9

5
5 4 3 2 1
Output :
1 2 3 4 5
**/
