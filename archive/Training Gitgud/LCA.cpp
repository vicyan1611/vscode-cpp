#include <iostream>
#include <vector>
#include <fstream>
#define Nmax 1005
#define logN 13
using namespace std;
int T,n,q,h[Nmax],p[logN][Nmax];
vector <int> adj[100004];
void dfs(int u, int par)
{
    for (int v:adj[u])
    {
        if (v==par) continue;
        p[0][v]=u;
        h[v]=h[u]+1;
        dfs(v,u);
    }
}
int solve(int u,int v)
{
    if (h[u]>h[v]) swap(u,v);
    for (int k=logN-1;k>=0;--k)
    {
        if (h[v]-(1<<k)>=h[u])
        {
            v=p[k][v];
        }
    }
    if (u==v) return v;
    for (int k=logN-1;k>=0;--k)
    {
        if (p[k][u]!=p[k][v])
        {
            u=p[k][u];
            v=p[k][v];
        }
    }
    return p[0][u];
}
void enter()
{
    cin>>T;
    int cnt=0;
    while (T--)
    {
        cnt++;
        cout<<"Case "<<cnt<<":"<<endl;
        cin>>n;
        for (int i=0;i<logN;++i)
            for (int j=1;j<=n;++j)
                p[i][j]=0;
 
        for (int i=1;i<=n;++i)
        {
            h[i]=0;
            int m;
            adj[i].clear();
            cin>>m;
            for (int j=1;j<=m;++j)
            {
                int v;
                cin>>v;
                adj[i].push_back(v);
            }
        }
        h[1]=1;
        dfs(1,0);
        for (int k=1;k<logN;++k)
        {
            for (int i=1;i<=n;++i)
                p[k][i]=p[k-1][p[k-1][i]];
        }
        cin>>q;
        while (q--)
        {
            int u,v;
            cin>>u>>v;
            cout<<solve(u,v)<<endl;
        }
    }
}
int main()
{
   // freopen("LCA.inp","r",stdin);
   // freopen("LCA.out","w",stdout);
    enter();
    return 0;
} 