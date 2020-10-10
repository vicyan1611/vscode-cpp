#include <bits/stdc++.h>
using namespace std;
vector <pair <int,int>> f[200004];
queue <int> q;
int n,cost[200005];
bool vis[200005];
void bfs(int s)
{
    for (int i=1;i<=n;++i)
        cost[i]=1e9;
    vis[s]=true;
    cost[s]=0;
    q.push(s);
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (pair<int,int> v:f[u])
        {
            if (vis[v.first]==false)
            {
                cost[v.first]=min(cost[v.first],cost[u]+v.second);
                q.push(v.first);
                vis[v.first]=true;
            } else 
            {
                cost[v.first]=min(cost[v.first],cost[u]+v.second);
            }
        }
    }
}
int main()
{
    freopen("689B.inp","r",stdin);
    cin>>n;
    for (long long i=1;i<=n;++i)
    {
        int v;
        cin>>v;
        if (i==1)
        {
            if (v!=i) f[i].push_back({v,1});
            f[i].push_back({i+1,1});
        } else if (i==n)
        {
            if (v!=i) f[i].push_back({v,1});
            f[i].push_back({i-1,1});
        } else
        {
            if (v!=i) f[i].push_back({v,1});
            f[i].push_back({i-1,1});
            f[i].push_back({i+1,1}); 
        }
    }
    bfs(1);
    for (int i=1;i<=n;++i)
        cout<<cost[i]<<" ";
    return 0;
}