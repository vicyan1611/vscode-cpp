/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "transnet"
#define endl '\n'
using namespace std;
const int Nmax = 1e5 + 5;
vector <pair <int, int>> adj[Nmax];
bool vis[Nmax];
int cost[Nmax];
int n, m, k;
int cost1[Nmax], cost2[Nmax];
void dijkstra(int s)
{
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    for (int i = 1; i <= n; ++i)
    {
        vis[i] = false;
        cost[i] = 1e9 + 7;
    }
    cost[s] = 0;
    pq.push(make_pair(0, s));
    while (!pq.empty())
    {
        int u = pq.top().second;
        int cst = pq.top().first;
        vis[u] = true;
        pq.pop();
        for (auto i: adj[u])
        {
            int v = i.first;
            int w = i.second;
            if (vis[v] == true || cst + w >= cost[v]) continue;
            cost[v] = cst + w;
            pq.push({cost[v], v});
        }
    }
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int s, t;
    cin >> n >> m >> k >> s >> t;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }
    dijkstra(s);
    for (int i = 1; i <= n; ++i)
    {
        cost1[i] = cost[i];
    }
    dijkstra(t);
    for (int i = 1; i <= n; ++i)
        cost2[i] = cost[i];
    int res = 1e9 + 7;
    for (int i = 1; i <= k; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (i == 3)
        {
            cout << cost1[u] << " " << cost2[v] << endl << cost1[v] << " " << cost2[u] << endl;
        }
        res = min(res, cost1[u] + cost2[v] + w);
        res = min(res, cost1[v] + cost2[u] + w);
        cout << res << endl;
    }
    return 0;
}