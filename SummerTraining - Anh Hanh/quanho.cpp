/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "quanho"
#define endl '\n'
#define oo 1e18;
using namespace std;
const long long Nmax = 1e5 + 5;
long long n, m, pie[Nmax], dis[Nmax];
long long dp[Nmax];
vector <pair <long long, long long>> adj[Nmax];
priority_queue <pair <long long, long long>, vector <pair <long long, long long>>, greater <pair <long long, long long>>> pq;
bool vis[Nmax];
void dijkstra()
{
    for (long long i = 1; i <= n; ++i)
    {
        dis[i] = oo;
    }
    dis[1] = 0;
    dp[1] = pie[1];
    pq.push({dis[1],1});
    while (!pq.empty())
    {
        long long u = pq.top().second;
        pq.pop();
        vis[u] = true;
        for (auto i: adj[u])
        {
            long long v = i.first;
            long long w = i.second;
            if (vis[v] == false)
            {
                if (dis[u] + w < dis[v])
                {
                    dis[v] = dis[u] + w;
                    dp[v] = dp[u] + pie[v];
                    pq.push({dis[v], v});
                } else if (dis[u] + w == dis[v])
                {
                    if (dp[v] < dp[u] + pie[v])
                    {
                        dp[v] = dp[u] + pie[v];
                    }
                }
            }
        }
    }
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (long long i = 1; i <= n; ++i)
    {
        cin >> pie[i];
    }
    cin >> m;
    for (long long i = 1; i <= m; ++i)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u, w});
    }
    dijkstra();
    if (dis[n] == 1e18) cout << "impossible"; else
    {
        cout << dis[n] << " " << dp[n];
    }
    return 0;
}