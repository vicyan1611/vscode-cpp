#include <iostream>
#include <fstream>
using namespace std;
const int Nmax = 1e3 + 5;
int n, time, vis[Nmax], adj[Nmax][Nmax], assign[Nmax];
bool dfs(int u, int x)
{
    if (vis[u] == time) return false;
    vis[u] = time;
    for (int i = 1; i <= n; ++i)
    {
        if (adj[u][i] == 0 || adj[u][i] < x) continue;
        if (assign[i] == 0 || dfs(assign[i], x))
        {
            assign[i] = u;
            return true;
        }
    }
    return false;
}
bool solve(int x)
{
    for (int i = 1; i <= n; ++i)
    {
        assign[i] = vis[i] = 0;
    }
    int cnt = 0;
    time = 0;
    for (int i = 1; i <= n; ++i)
    {
        time++;
        if (dfs(i, x)) cnt++;
    }
    if (cnt == n) return true; else return false;
}
int main()
{
    freopen("nangsuat.inp","r",stdin);
    freopen("nangsuat.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cin >> adj[i][j];
    }
    int l = 1, r = 20000, k = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (solve(mid))
        {
            l = mid + 1;
            k = mid;
        } else r = mid - 1;
    }
    cout << k;
    return 0;
}