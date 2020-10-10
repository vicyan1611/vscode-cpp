#include <iostream>
#include <vector>
using namespace std;
int n,m;
int fi[100005];
vector <int> f[100005];
int dfs(int u)
{
    int &res=fi[u];
    if (res!=-1) return res;
    res=0;
    for (int i:f[u])
    {
        res=max(res,dfs(i)+1);
    }
    return res;
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=m;++i)
    {
        int u,v;
        cin>>u>>v;
        f[u].push_back(v);
    }
    for (int i=1;i<=n;++i)
        fi[i]=-1;
    int res=0;
    for (int i=1;i<=n;++i)
    {
        res=max(res,dfs(i));
    }
    cout<<res;
    return 0;
}