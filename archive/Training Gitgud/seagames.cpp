/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "seagames"
#define endl '\n'
using namespace std;
const int Nmax = 205;
int n, k, c[Nmax];
int a[Nmax][Nmax], ti;
int vis[Nmax];
bool dfs(int u, int x)
{
    if (vis[u] == ti) return false; else vis[u] = ti;
    for (int i = 1; i <= n; ++i)
    {
        int w = a[u][i];
        if (w == 0 || i == u) continue;
        if (assign[i] == false || adj)
    }
    return false;

}
bool solve(int x)
{
    ti = 0;
    for (int i = 1; i <= n; ++i)
    {
        ++ti;
        if (!dfs(i, x)) return false;
    }
    return true;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= k; ++i)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
    int l = 1, r = 30004, k = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (solve(mid))
        {
            r = mid - 1;
            k = mid;
        } else l = mid + 1;
    }
    return 0;
}