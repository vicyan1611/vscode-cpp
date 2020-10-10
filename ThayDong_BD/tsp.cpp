/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "tsp"
#define endl '\n'
using namespace std;
const long long Nmax = 1e6 + 5;
long long a[Nmax];
long long n, m;
vector <long long> adj[Nmax];
long long x[Nmax], y[Nmax], res = -1;
void solve(long long d, long long h)
{
    for (auto u: adj[d])
    {
        for (auto v: adj[h])
        {
            if (v != d && u != h && u != v)
            {
                res = max(a[v] + a[u] + a[d] + a[h], res);
            }
        }
    }
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (long long i = 1; i <= n; ++i) cin >> a[i];
    for (long long i = 1; i <= m; ++i)
    {
        cin >> x[i] >> y[i];
        adj[x[i]].push_back(y[i]);
        adj[y[i]].push_back(x[i]);
    }
    for (long long i = 1; i <= m; ++i)
    {
        solve(x[i], y[i]);
    }
    cout << res;
    return 0;
}