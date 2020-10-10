#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int Nmax = 1e5 + 5;
int n, m, k;
int ik[19], cost[Nmax], costk[19][19], f[18][1<<18];
bool vis[Nmax];
map <int, int> ki;
vector <pair <int, int>> adj[Nmax];
priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> dq;
void save(int s)
{
    for (int i = 1; i <= k; ++i)
    {
        costk[ki[s]][i] = cost[ik[i]];
    }
}
void dijkstra(int s)
{
    for (int i = 1; i <= n; ++i)
    {
        cost[i] = 1e9;
        vis[i] = false;
    }
    cost[s] = 0;
    dq.push({0,s});
    while (!dq.empty())
    {
        int u = dq.top().second;
        dq.pop();
        vis[u] = true;
        for (auto i: adj[u])
        {
            int v = i.first;
            int w = i.second;
            if (vis[v] == false && cost[u] + w < cost[v])
            {
                cost[v] = cost[u] + w;
                dq.push({cost[v], v});
            }
        }
    }
    save(s);
}
int trau(int i, int used)
{
    if (used == k - 1)
    {
        return 0;
    }
    int &res = f[i][used];
    if (res != -1) return res;
    for (int i = 1; i <= n; ++i)
    {
    }
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i)
    {
        cin >> ik[i];
    }
    sort(1 + ik, 1 + ik + k);
    for (int i = 1; i <= k; ++i)
    {
        ki[ik[i]] = i;
    }
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int res = 1e9;
    for (int i = 1; i <= n; ++i)
    {
        res = min(res, trau(i,0));
    }
    return 0;
}