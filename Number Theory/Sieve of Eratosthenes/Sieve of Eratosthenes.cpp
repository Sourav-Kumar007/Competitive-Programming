
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
bool marked[10000005];

void sieve()
{
    int i,j,mx=10000000;
    vector <int> primes;
    primes.pb(2);

    for(i=3; i*i<=mx; i+=2)
    {
        if(marked[i]==false)
        {
            for(j=i*i; j<=mx; j+=(i+i))
            {
                marked[j] = true;
            }
        }
    }

    for(i=3; i<=mx; i+=2)
    {
        if(marked[i]==false)
        {
            primes.pb(i);
        }
    }

    for(i=0; i<50; i++)
    {
        cout << primes[i] << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve();
}
/**
Test Case :

**/
