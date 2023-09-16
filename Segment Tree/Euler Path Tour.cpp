#include<bits/stdc++.h>
 
#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     //cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
using namespace std;
 
const ll inf=1e18;
const int mod=1e9+7;
const int M=200009;
int n;
int c[M];
vector<int>adj[M];
int tym=0;
int st[M],en[M];
int tre[4*M],lz[4*M];
int id[M];
void build(int pos,int l,int r)
{
    if(l==r)
    {
        tre[pos]=c[id[l]];
        return ;
    }
    int mid=(l+r)>>1;
    build(2*pos,l,mid);
    build(2*pos+1,mid+1,r);
    tre[pos]=tre[2*pos]+tre[2*pos+1];
}
void propagate(int pos,int l,int r)
{
    lz[pos]=lz[pos]%2;
    if(lz[pos]==0)return ;
    tre[pos]=(r-l+1)-tre[pos];
    if(l!=r)
    {
        lz[2*pos]++;
        lz[2*pos+1]++;
    }
    lz[pos]++;
}
void update(int pos,int l,int r,int I,int J)
{
    propagate(pos,l,r);
    if(l>J || r<I)return ;
    if(I<=l && J>=r)
    {
        lz[pos]++;
        propagate(pos,l,r);
        return ;
    }
    int mid=(l+r)>>1;
    update(2*pos,l,mid,I,J);
    update(2*pos+1,mid+1,r,I,J);
    tre[pos]=tre[2*pos]+tre[2*pos+1];
}
int qry(int pos,int l,int r,int I,int J)
{
    propagate(pos,l,r);
    if(l>J || r<I)return 0;
    if(I<=l && J>=r)
    {
        return tre[pos];
    }
    int mid=(l+r)>>1;
    int x=qry(2*pos,l,mid,I,J);
    int y=qry(2*pos+1,mid+1,r,I,J);
    tre[pos]=tre[2*pos]+tre[2*pos+1];
    return (x+y);
}
void dfs(int u)
{
    st[u]=++tym;
    id[tym]=u;
    for(auto v:adj[u])
    {
        dfs(v);
    }
    en[u]=tym;
}
 main()
 
{
    fast
    cin>>n;
    f(i,2,n)
    {
        int x;
        cin>>x;
        adj[x].pb(i);
    }
    dfs(1);
    f(i,1,n)cin>>c[i];
    build(1,1,n);
    int q,ses=0;
    cin>>q;
    done("hi")
    while(q--)
    {
        string typ;
        int x;
        cin>>typ>>x;
        if(typ=="pow")
        {
             update(1,1,tym,st[x],en[x]);
        }
        else
        {
           ses=qry(1,1,tym,st[x],en[x]);
           cout<<ses<<"\n";
        }
    }
    return 0;
 
}