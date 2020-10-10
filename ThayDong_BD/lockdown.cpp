/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "lockdown"
#define endl '\n'
using namespace std;
const long long Nmax = 505;
long long n, a[Nmax][Nmax], e[Nmax][Nmax], cnt[Nmax][Nmax];
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (long long i = 1; i <= n; ++i)
    {
        for (long long j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            if (a[i][j] == -1)
            {
                a[i][j] = 1e14;
            } else
            {
                cnt[i][j] = 1;
            }
            e[i][j] = a[i][j];
        }
    }
    for (long long k = 1; k <= n; ++k)
    for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= n; ++j)
    {
        if (i == k || i ==j || k == j) continue;
        if (a[i][k] + a[k][j] < a[i][j]) 
        {
            a[i][j] = a[i][k] + a[k][j];
            cnt[i][j] = cnt[i][k] * cnt[k][j];
        } else
        if (a[i][k] + a[k][j] == a[i][j]) cnt[i][j] += cnt[i][k] * cnt[k][j];
    }
    long long res = 0;
    for (long long u = 1; u <= n; ++u)
    for (long long v = 1; v <= n; ++v)
    {
        long long current = 0;
        if (u == v || a[u][v] == 1e14) continue;
        for (long long k = 1; k <= n; ++k)
        {
            if (a[1][u] + e[u][v] + a[v][k]== a[1][k] && cnt[1][u] * cnt[v][k] == cnt[1][k])
            {
                current++;
            }
        }
        res = max(res, current);
    }
    cout << res;
    return 0;
}