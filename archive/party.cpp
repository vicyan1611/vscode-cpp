/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "party"
#define endl '\n'
using namespace std;
const long long Nmax = 1e3 + 5;
bool vis[Nmax];
long long cost[Nmax], n, m;
vector <pair <long long, long long>> adj[Nmax];
long long cost_from_x[Nmax];
void dijkstra(long long s)
{
    for (long long i = 1; i <= n; ++i)
    {
        vis[i] = false;
        cost[i] = (long long) 1e9 + 7;
    }
    priority_queue <pair <long long, long long>, vector <pair <long long, long long>>, greater <pair <long long, long long>>> pq;
    cost[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        long long u = pq.top().second;
        vis[u] = true;
        long long cst = pq.top().first;
        pq.pop();
        for (auto i: adj[u])
        {
            long long v = i.first;
            long long w = i.second;
            if (vis[v] == false && cst + w < cost[v])
            {
                cost[v] = cst + w;
                pq.push({cost[v], v});
            }
        }
    }
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long x;
    cin >> n >> m >> x;
    for (long long i = 1; i <= m; ++i)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dijkstra(x);
    for (long long i = 1; i <= n; ++i)
    {
        cost_from_x[i] = cost[i];
    }
    long long res = 0;
    for (long long i = 1; i <= n; ++i)
    {
        if (i != x)
        {
            dijkstra(i);
            res = max(res, cost[x] + cost_from_x[i]);
        }
    }
    cout << res;
    return 0;
}