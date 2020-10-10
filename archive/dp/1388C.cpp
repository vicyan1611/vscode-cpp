#include <iostream>
#include <vector>
using namespace std;
const long long Nmax = 1e5 + 5;
long long n, m, p[Nmax], h[Nmax], g[Nmax], pop[Nmax];
bool ok;
vector <long long> adj[Nmax];

void dfs(long long u, long long par)
{
    long long sums_g = 0;
    pop[u] = p[u];
    for (long long v: adj[u])
    {
        if (v != par)
        {
            dfs(v, u);
            sums_g += g[v];
            pop[u] += pop[v];
        }
    }
    if ((pop[u] + h[u]) %2 != 0) ok = false;
    g[u] = (h[u] + pop[u]) / 2;
    if (g[u] < sums_g) ok = false;
    if (g[u] < 0 || g[u] > pop[u]) ok = false;
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (long long i = 1; i <= n; ++i)
            cin >> p[i];
        for (long long i = 1; i <= n; ++i)
            cin >> h[i];
        for (long long i = 1; i <= n; ++i)
        {
            pop[i] = 0;
            g[i] = 0;
            adj[i].clear();
        }
        for (long long i = 1; i < n; ++i)
        {
            long long u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ok = true;
        dfs(1, 0);
        if (ok) cout << "YES" << endl; else cout << "NO" << endl;
    }
    return 0;
}