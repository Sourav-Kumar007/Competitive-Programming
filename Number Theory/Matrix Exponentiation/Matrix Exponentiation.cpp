/// Topic : Matrix Exponentiation (From Number theory part)
/// Reference : CodeNCode (You Tube channel)
/// Time Complexity : O(M^3 * logN) [ here M is the dimension of the Matrix and N is the power ]

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
int arr[101][101],I[101][101];

void mult(int A[][101],int B[][101],int dim)
{
    int product[dim+2][dim+2];
    int sum = 0,i,j,k;

    for(i=1; i<=dim; i++)
    {
        for(j=1; j<=dim; j++)
        {
            for(k=1; k<=dim; k++)
            {
                sum += (A[i][k] * B[k][j]);
            }
            product[i][j] = sum;
            sum = 0;
        }
    }

    for(i=1; i<=dim; i++)
    {
        for(j=1; j<=dim; j++)
        {
            A[i][j] = product[i][j];
        }
    }

}

void power(int A[][101],int dim,int n)
{
    int i,j;
    for(i=1; i<=dim; i++)
    {
        for(j=1; j<=dim; j++)
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
        /// I = I * A;
        mult(I,A,dim);
    }
    **/

    while(n)
    {
        if(n&1^1)
        {
            mult(A,A,dim);
            n/=2;
        }
        else
        {
            mult(I,A,dim);
            n--;
        }
    }

    for(i=1; i<=dim; i++)
    {
        for(j=1; j<=dim; j++)
        {
            A[i][j] = I[i][j];
        }
    }

}
void solve()
{
    int n,dim,i,j;
    cin >> dim >> n;
    for(i=1; i<=dim; i++)
    {
        for(j=1; j<=dim; j++)
        {
            cin >> arr[i][j];
        }
    }

    power(arr,dim,n);

    for(i=1; i<=dim; i++)
    {
        for(j=1; j<=dim; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
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
1
2 1
1 2
2 3
1
2 3
0 1
1 1
**/
