#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int n,m,vis[37],res,x[37],op[37];
vector <int > f[37];
bool check(int z)
{
    for (int i=1;i<=n;++i) op[i]=false;
    for (int i=1;i<=z;++i)
    {
        op[x[z]]=true;
        for (int j:f[x[z]])
            op[j]=true;
    }
    for (int i=1;i<=n;++i)
    {
        if (op[i]==false) return false;
    }
    return true;
}
void trau(int i)
{
    for (int j=1;j<=n;++j)
    {
        if (vis[j]==false)
        {
            vis[j]=true;
            x[i]=j;
            if (i==n)
            {
                if (check(n)) res=min(res,i);
                
            } else
            {
                if (check(i))
                {
                    res=min(res,i);
                    vis[j]=false;
                    return;
                } else
                trau(i+1);
            } 
            vis[j]=false;
        }
    }
}
int main()
{
    freopen("LIGHTS.inp","r",stdin);
    freopen("LIGHTS.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;++i)
    {
        int u,v;
        cin>>u>>v;
        f[u].push_back(v);
        f[v].push_back(u);
    }
    res=100000;
    trau(1);
    cout<<res;
    return 0;
}