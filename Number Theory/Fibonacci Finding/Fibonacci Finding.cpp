/// Number Theory
/// Fibonacci Series
/// Finding nth term of this Series
/// Reference : CodeNCode (You Tube Channel)
/// Time Complexity : OlogN


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
int F[100];
int arr[3][3],I[3][3];

void mult(int A[][3],int B[][3])
{
    int product[3][3];
    int sum = 0,i,j,k;

    for(i=1; i<=2; i++)
    {
        for(j=1; j<=2; j++)
        {
            for(k=1; k<=2; k++)
            {
                sum += (A[i][k] * B[k][j]);
            }
            product[i][j] = sum;
            sum = 0;
        }
    }

    for(i=1; i<=2; i++)
    {
        for(j=1; j<=2; j++)
        {
            A[i][j] = product[i][j];
        }
    }
}


void power(int A[][3],int n)
{
    int i,j;
    for(i=1; i<=2; i++)
    {
        for(j=1; j<=2; j++)
        {
            if(i==j)
            {
                I[i][j] = 1;
            }
            else
            {
                I[i][j] = 0;
            }
        }
    }

    /**
    for(i=1; i<=n; i++)
    {
        I = I * A;
        mult(I,A);
    }
    **/

    while(n)
    {
        if(n&1^1)
        {
            n/=2;
            mult(A,A);
        }
        else
        {
            n--;
            mult(I,A);
        }
    }

    for(i=1; i<=2; i++)
    {
        for(j=1; j<=2; j++)
        {
            A[i][j] = I[i][j];
        }
    }


}

void solve()
{
    int n,i,j;
    cin >> F[1] >> F[2] >> n;

    for(i=1; i<=2; i++)
    {
        for(j=1; j<=2; j++)
        {
            if(i==1 && j==1)
            {
                arr[i][j] = 0;
            }
            else
            {
                arr[i][j] = 1;
            }
        }
    }

    power(arr,n-1);

    cout << (F[1]*arr[1][1]) + (F[2]*arr[2][1]) << endl;
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
3
7
9
10
**/
