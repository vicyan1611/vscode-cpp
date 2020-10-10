#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define oo 1e18;
using namespace std;
const int Nmax = 1e5 + 5;
long long n, m, s, t;
long long cost[Nmax], trace[Nmax];
bool vis[Nmax];
stack <long long> res;
vector <pair <long long, long long>> adj[Nmax];
priority_queue<pair <long long, long long>, vector<pair <long long, long long>>, greater <pair <long long, long long>>> pq;
void tra()
{
    while (t!=0)
    {
        res.push(t);
        t=trace[t];
    }
}
void dijkstra()
{
    for (long long i = 1; i <= n; ++i)
    {
        cost[i] = oo;
    }
    cost[s] = 0;
    trace[s] = 0;
    pq.push({0,s});
    while (!pq.empty())
    {
        long long u = pq.top().second;
        vis[u] = true;
        pq.pop();
        for (auto i: adj[u])
        {
            long long v = i.first;
            long long w = i.second;
            if (vis[v] == false && cost[u] + w < cost[v])
            {
                cost[v] = cost[u] + w;
                trace[v] = u;
                pq.push({cost[v], v});
            }
        }
    }
}
int main()
{
    cin >> n >> m >> s >> t;
    for (long long i = 1; i <= m; ++i)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra();
    cout << cost[t] << endl;
    tra();
    while (!res.empty())
    {
        cout << res.top() << " ";
        res.pop();
    }
    return 0;
}