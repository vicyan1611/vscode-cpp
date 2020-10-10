#include <iostream>
using namespace std;
long long check,n,m,adj[25][25],rem[24][1<<20],f[24][1<<20];
long long trau(long long i,long long visited)
{
    if (visited==check)
    {
        if (adj[i][1]!=0)
        return adj[i][1]; else return 1e9;
    } 
    long long &res=f[i][visited];
    if (res!=-1) return res;
    res=1e9;
    for (long long j=1;j<=n;++j)
    {
        if ((adj[i][j]==0)||(((visited>>(j-1))&1)==1)) continue;
            long long tmp=trau(j,(visited|(1<<(j-1))))+adj[i][j];
            if (res>tmp)
            {
                rem[i][visited]=j;
                res=tmp;
            }
    }
    return res;
}
int main()
{
    cin>>n>>m;
    for (long long i=1;i<=m;++i)
    {
        long long u,v,w;
        cin>>u>>v>>w;
        adj[u][v]=w;
    }
    check=0;
   
    for (long long i=1;i<=n;++i)
    {
        check=(check<<1)^1;
    }
     for (long long i=0;i<=n;++i)
    {
        for (long long j=0;j<=1<<20;++j)
            f[i][j]=-1;
    }
    cout<<trau(1,1)<<endl;
    int i=0,j=0;
    rem[0][0]=1;
    while (rem[i][j]!=0)
    {
        cout<<rem[i][j]<<" ";
        i=rem[i][j];
        j=j|(1<<(i-1));
    }
    return 0;
}