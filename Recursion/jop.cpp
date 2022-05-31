#include<bits/stdc++.h>
using namespace std;
vector <int> v;
int ans;

void solve(int k,int idx)
{
    if(v.size() == 1)
    {
        ans = v[0];
        return ;
    }
    int x = (idx + k) % v.size();
    v.erase(v.begin() + x);
    solve(k,x);
}

int main()
{
    int n,k,i;
    cin >> n >> k;
    k--;
    for(i=1; i<=n; i++)
    {
        v.push_back(i);
    }
    solve(k,0);
    cout << ans << endl;
}
