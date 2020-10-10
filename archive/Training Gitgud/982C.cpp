#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
long long vis[100005], res=0;
vector <long long> f[100005];
long long dfs(long long u)
{
    long long dem=1;
    vis[u]=true;
    for (long long v:f[u])
    {
        if (vis[v]==false)
        {
            dem+=dfs(v);
        }
    }
    if (dem%2==0)
    {
        res++;
        return 0;
    }
    return dem;
}
int main()
{
   // freopen("982C.inp","r",stdin);
    long long n,u,v;
    cin>>n;
    for (long long i=1;i<n;++i)
    {
        cin>>u>>v;
        f[u].push_back(v);
        f[v].push_back(u);
    }
    if (n%2!=0) cout<<-1; else
    {
        long long tmp=dfs(1);
        cout<<--res;
    }
    return 0;
}