/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "tour"
#define endl '\n'
using namespace std;
const int Nmax = 200005;
int n, num[Nmax], cnt, low[Nmax];
vector <int> adj[Nmax];
int res;
void dfs(int u, int par)
{
    num[u] = low[u] = ++cnt;
    low[u] = 1e9;
    for (auto v: adj[u])
    {
        if (v == par) continue;
        if (num[v] == 0)
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (num[v] <= low[v]) res++;
        } else low[u] = min(low[u], num[v]);
    }
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);\
    cnt = 0;
    cin >> n; 
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(n + 1);
        adj[v].push_back(n + 1);
        adj[n+1].push_back(v);
        adj[n+1].push_back(u);
    }
    dfs(1, 0);
    cout << res;
    return 0;
}