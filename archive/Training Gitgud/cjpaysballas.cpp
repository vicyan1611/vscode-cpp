#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
const int Nmax  = 1e5 + 5;
const int oo = 1e9;
vector <int> adj[Nmax];
queue <int> q;
stack <int> res;
bool vis[Nmax];
int cost[Nmax], trace[Nmax];
void bfs(int s)
{
    vis[s] = true;
    cost[s] = 0;
    trace[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (vis[v] == false)
            {
                vis[v] = true;
                cost[v] = cost[u] + 1;
                trace[v] = u;
                q.push(v);
            }
        }
    }
}
int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++i)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i)
    {
        cost[i] = oo;
        trace[i] = oo;
        sort(adj[i].begin(), adj[i].end());
    }
    bfs(s);
    while (t != 0)
    {
        res.push(t);
        t = trace[t];
    }
    while (!res.empty())
    {
        cout << res.top() << " ";
        res.pop();
    }
    return 0;
}