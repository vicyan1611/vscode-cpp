#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
ifstream fi ("clues.inp");
ofstream fo ("clues.out");
vector <int> adj[100004];
int cnt,sz[100005];
bool vis[1000004];
int chiadetri(int a,int n)
{
    if (n==1)
    {
        return a;
    }
    int tmp=chiadetri(a,n/2);
    if (n&1) return tmp*tmp*a; else return tmp*tmp;
}
void dfs(int u)
{
    vis[u]=true;
    cnt++;
    for (int v:adj[u])
    {
        if (vis[v]==false)
        {
            dfs(v);
        }
    }
}
int main()
{
    int n,m,p;
    fi>>n>>m>>p;
    for (int i=1;i<=m;++i)
    {
        int u,v;
        fi>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int dem=0;
    for (int i=1;i<=n;++i)
    {
        if (vis[i]==false)
        {
            cnt=0;
            dfs(i);
            sz[++dem]=cnt;
        }   
    }
    int res=1;
    for (int i=1;i<=dem;++i)
    {
        res=(res*sz[i]%p)%p;
    }       
    fo<<(res*chiadetri(n,dem-2)%p)%p;
    return 0;
}