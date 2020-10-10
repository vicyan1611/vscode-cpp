#include <iostream>
#include <fstream>
#include <vector>
#define endl '\n'
#define Nmax 100005
#define Nlog 19
using namespace std;
int n,h[Nmax],p[Nlog][Nmax],mmax[Nlog][Nmax],K,mmin[Nlog][Nmax];
vector <pair <int,int>> adj[Nmax];
void dfs (int u, int par)
{ 
    for (auto v:adj[u])
    {
        if (v.first==par) continue;
        h[v.first]=h[u]+1;
        p[0][v.first]=u;
        mmax[0][v.first]=mmin[0][v.first]=v.second;
        dfs(v.first,u);
    }
}
void solve (int u, int v)
{
    int rmin=1e9,rmax=-1;
    if (h[u]>h[v]) swap(u,v);
    for (int k = Nlog-1; k >= 0; k--)
    {
        if (h[v] - (1<<k) >= h[u])
        {
            rmin=min(rmin,mmin[k][v]);
            rmax=max(rmax,mmax[k][v]);
            v=p[k][v];
        }
    }
    if (u == v)
    {
        cout << rmin << " " << rmax <<endl;
        return;
    }
    for (int k = Nlog-1; k >= 0; --k)
    {
        if (p[k][u] != p[k][v])
        {
            rmin=min( rmin , mmin[k][u] );
            rmin=min( rmin , mmin[k][v] );
            rmax=max( rmax , mmax[k][u] );
            rmax=max( rmax , mmax[k][v] );
            u=p[k][u];
            v=p[k][v];
        }
    }
    rmax=max( rmax , mmax[0][u] );
    rmax=max( rmax , mmax[0][v] );
    rmin=min( rmin , mmin[0][u] );
    rmin=min( rmin , mmin[0][v] );
    cout << rmin << " " << rmax <<endl;
}
int main()
{
    //freopen("lubenica.inp","r",stdin);
    //freopen("lubenica.out","w",stdout);
    cin>>n;
    for (int i = 0; i < n-1; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for (int k = 0; k < Nlog; ++k)
    {
        for (int i = 1;i <= n; ++i)
        {
            p[k][i]=mmax[k][i]=mmin[k][i]=0;
        }
    }
    h[1]=1;
    dfs(1,0);
    for (int k = 1; k < Nlog; k++)
    {
        for (int j = 1; j <= n; ++j)
        {
            mmin[k][j]=min( mmin[k-1][j] , mmin[k-1][p[k-1][j]] );
            mmax[k][j]=max( mmax[k-1][j] , mmax[k-1][p[k-1][j]] ); 
            p[k][j]=p[k-1][p[k-1][j]];
        }
    }
    cin>>K;
    while (K--)
    {
        int u,v;
        cin>>u>>v;
        solve(u,v);       
    }
    
    return 0; 
}