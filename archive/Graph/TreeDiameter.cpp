#include <iostream>
#include <vector>
using namespace std;
const int Nmax = 2e5 + 5;
int n, nxt_ver;
vector <int> adj[Nmax];
int vis[Nmax], cost;
void dfs(int u)
{
    for (int v: adj[u])
    {
        if (vis[v] == 0)
        {
            vis[v] = vis[u] + 1;
            if (vis[v] > cost)
            {
                cost = vis[v];
                nxt_ver = v;
            }
            dfs(v);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cost = 0;
    vis[1] = 1;
    dfs(1);
    for (int i = 1; i <= n; ++i) vis[i] = 0;
    cost = 0;
    vis[nxt_ver] = 1;
    dfs(nxt_ver);
    if (n == 1)  cout << 0; else cout << cost - 1;
}