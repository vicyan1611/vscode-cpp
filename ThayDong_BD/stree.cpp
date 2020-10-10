/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "stree"
#define endl '\n'
using namespace std;
const int Nmax = 5e3 + 5;
int a[Nmax];
vector <int> adj[Nmax], g[Nmax];
int p[Nmax], n, child_cnt[Nmax];
bool leaf[Nmax];
void init(int u, int par)
{
    bool isLeaf = 1;
    for (auto v: g[u])
    {
        if (v != par)
        {
            adj[u].push_back(v);
            p[v] = u;
            init(v, u);
            child_cnt[u] += child_cnt[v];
            isLeaf = 0;
        }
    }
    leaf[u] = isLeaf;
    child_cnt[u] += isLeaf;
}
int f[Nmax][Nmax];
int trau(int u, int s, int par)
{
    if (f[u][s] != -1) return f[u][s];
    int &res = f[u][s];
    res = 1e9 + 9;
    if (adj[u].size() == 0)
    {
        if (s > 1 || s < 0) return 1e9 + 9;
        return f[u][s] = abs(a[u] - s);
    } else
    if (adj[u].size() == 1)
    {
        int v = adj[u][0];
        res = trau(v, s, u) + abs(a[u] - s);
    } else
    if (adj[u].size() == 2)
    {
        int v1 = adj[u][0];
        int v2 = adj[u][1];
        for (int i = 0, j = s; i <= s; ++i, --j)
        {
            if (i <= child_cnt[v1] && j <= child_cnt[v2]) res = min(res, trau(v1, i, u) + trau(v2, j, u) + abs(a[u] - s));

        }
    }
    return res;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    init(1, -1);
    for (int i = 1; i < Nmax; ++i)
    {
        for (int j = 0; j < Nmax; ++j) f[i][j] = -1;
    }
    int res = 1e9 + 9;
    for (int i = 0; i <= child_cnt[1]; ++i)
    {
        res = min(res, trau(1, i, -1));
    }
    cout << res;
    return 0;
}