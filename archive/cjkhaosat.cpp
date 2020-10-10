#include <iostream>
using namespace std;
const int Nmax = 405;
int n, m, q;
int adj[Nmax][Nmax];
int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            adj[i][j] = 1e9;
        adj[i][i] = 0;
    }   
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
    }
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << adj[u][v] << endl;
    }
    return 0;
}