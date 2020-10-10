/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "roads"
#define endl '\n'
using namespace std;
const int Nmax = 1e5 + 5;
int n, m, number, num[Nmax], low[Nmax], cnt, res;
vector <int> adj[Nmax];
int vis[Nmax];
bool cycle;
void dfs(int u, int par)
{
    vis[u] = 1;
    for (int v: adj[u])
    {
        if (v == par) continue;
        if (vis[v] == 0)
        {
            dfs(v, u);
        } else if (vis[v] == 1) cycle = true;
    }
    vis[u] = 2;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i] == false)
        {
            cycle = false;
            dfs(i, 0);
            res += (cycle == true) ? 0 : 1;
        }
    }
    cout << res;
    return 0;
}