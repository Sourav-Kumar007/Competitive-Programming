/// Topic : Matrix Exponentiation
/// Time Complexity : O(M^3) ,,,Here M is the order of Matrix,,,


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

void solve()
{
    int r1,c1,r2,c2,sum=0,i,j,k;
    cin >> r1 >> c1;
    int arr[r1+2][c1+2];
    for(i=1; i<=r1; i++)
    {
        for(j=1; j<=c1; j++)
        {
            cin >> arr[i][j];
        }
    }
    cin >> r2 >> c2;
    int brr[r2+2][c1+2];
    for(i=1; i<=r2; i++)
    {
        for(j=1; j<=c2; j++)
        {
            cin >> brr[i][j];
        }
    }
    int product [r1+2][c2+2];
    if(c1!=r2)
    {
        cout << "Sorry!" << endl;
    }
    else
    {
        for(i=1; i<=r1; i++)
        {
            for(j=1; j<=c2; j++)
            {
                for(k=1; k<=c1; k++)
                {
                    sum += (arr[i][k] * brr[k][j]);
                }
                product[i][j] = sum;
                sum = 0;
            }
        }
        cout << "Resultant Matrix : " << endl;
        for(i=1; i<=r1; i++)
        {
            for(j=1; j<=c2; j++)
            {
                cout << product[i][j] << " ";
            }
            cout << endl;
        }
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
