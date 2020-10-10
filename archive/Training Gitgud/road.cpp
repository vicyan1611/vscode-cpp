/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "road"
#define endl '\n'
using namespace std;
const long long Nmax = 5e3 + 5;
vector <pair <long long, long long>> adj[Nmax];
long long n, m, cost[Nmax], dp[Nmax];
bool vis[Nmax];
priority_queue <pair <long long, long long>, vector <pair <long long, long long>>, greater <pair <long long, long long>>> pq;
void dijkstra()
{
    for (long long i = 1; i <= n; ++i)
    {
        cost[i] = 1e18;
    }
    cost[1] = 0;
    dp[1] = 1;
    pq.push({cost[1], 1});
    while (!pq.empty())
    {
        long long u = pq.top().second;
        pq.pop();
        vis[u] = true;
        for (auto i: adj[u])
        {
            long long w = i.second;
            long long v = i.first;
            if (w + cost[u] < cost[v] && vis[v] == false)
            {
                cost[v] = cost[u] + w;
                dp[v] = dp[u];
                pq.push({cost[v], v});
            } else if (w + cost[u] == cost[v] && vis[v] == false)
            {
                dp[v] += dp[u];
            }
        }
    }
    cout << cost[n] << " " << dp[n] << endl;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (long long i = 1; i <= m; ++i)
    {
        long long k, u, v, l;
        cin >> k >> u >> v >> l;
        if (k == 1)
        {
            adj[u].push_back({v, l});
        }
        if (k == 2)
        {
            adj[u].push_back({v, l});
            adj[v].push_back({u, l});
        }
    }
    dijkstra();
    return 0;
}