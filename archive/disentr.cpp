/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "disentr"
#define endl '\n'
using namespace std;
const int Nmax  = 1e3 + 5;
int rd[Nmax], f[Nmax], cost[Nmax], ad[Nmax][Nmax],time_d[Nmax][Nmax];
int n, m, s, t, k, c;
bool vis[Nmax];
vector <pair <int, int>> adj[Nmax];
priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
void dijkstra()
{
    for (int i = 1; i <= n; ++i)
    {
        cost[i] = 1e9;
    }
    cost[s] = k;
    pq.push({k, s});
    while (!pq.empty())
    {
        int u = pq.top().second;
        vis[u] = true;
        pq.pop();
        for (auto v:adj[u])
        {
            if (vis[v.first] == false && cost[v.first] > cost[u] + v.second)
            {
                if (cost[u] >= time_d[u][v.first] - v.second && cost[u] <= time_d[u][v.first])
                {
                    cost[v.first] = max(cost[u], time_d[u][v.first]) + v.second;
                } else cost[v.first] = cost[u] + v.second;
                pq.push({cost[v.first], v.first});
            }
        }
    }
    cout << cost[t] -  k;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> s >> t >> k >> c;
    for (int i = 1; i <= c; ++i)
    {
        cin >> rd[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        ad[u][v] = ad[v][u]  = w;
    }
    for (int i = 2; i <= c; ++i)
    {
        time_d[rd[i-1]][rd[i]]  = time_d[rd[i]][rd[i-1]] = time_d[rd[i-2]][rd[i-1]]  + ad[rd[i-1]][rd[i]];
    }
    dijkstra();
    return 0;
}