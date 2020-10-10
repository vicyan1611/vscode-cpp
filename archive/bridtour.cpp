#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
const int Nmax = 200005;
int n, h[Nmax], p[19][Nmax], cha[Nmax], res;
vector <int> adj[Nmax];
int get_root(int u)
{
    if (cha[u] < 0) return u;
    return cha[u] = get_root(cha[u]);
}
void uni(int u, int v)
{
    if (h[u] > h[v]) swap(u, v);
    if (u == v) return;
    cha[u] += cha[v];
    cha[v] = u;
}
void jump(int u, int q)
{
    u = get_root(u);
    while (h[u] > h[q])
    {
        int v = get_root(p[0][u]);
        res--;
        uni(u, v);
        u = get_root(u);
    }
}
void dfs(int u, int par)
{
    for (int v: adj[u])
    {
        if (v == par) continue;
        h[v] = h[u] + 1;
        p[0][v] = u;
        dfs(v,u);
    }
}
int lca(int u, int v)
{
    if (h[u] > h[v]) swap(h[u], h[v]);
    for (int k = 18; k >= 0; --k)
    {
        if (h[v] - (1<<k) >= h[u])
        {
            v = p[k][v];
        }
    }
    if (u == v)
    {
        return u;
    }
    for (int k = 18; k >= 0; --k)
    {
        if (p[k][u] != p[k][v])
        {
            u = p[k][u];
            v = p[k][v];
        }
    }
    return p[0][u];
}
int main()
{
   // freopen("bridtour.inp","r",stdin);
   // freopen("bridtour.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    h[1] = 1;
    dfs(1, -1);
    res = n - 1;
    for (int i = 1; i < 19; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            p[i][j] = p[i-1][p[i-1][j]];
        }
    }
    int m;
    for (int i = 1; i <= n; ++i)
        cha[i] = -1;
    cin >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        int q = lca(u, v);
        jump(u, q);
        jump(v, q);
    }
    cout << res;
    return 0;
}