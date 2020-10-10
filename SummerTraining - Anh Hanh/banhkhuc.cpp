/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "banhkhuc"
#define endl '\n'
#define Mask(n) (1 << (n))
using namespace std;
const int Nmax = 505;
int n, k;
int a[Nmax][Nmax], ki[22], f[21][1 << 21];
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    }
    for (int i = 0; i < 21; ++i)
        for (int j = 0; j < Mask(k); ++j) f[i][j] = 2e9;
    for (int i = 0; i < k; ++i)
        cin >> ki[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int z = 1; z <= n; ++z)
                a[i][j] = min(a[i][j], a[i][z] + a[z][j]);
    for (int i = 0; i < k; ++i) f[i][Mask(i)] = a[1][ki[i]];
    for (int mask = 0; mask < Mask(k); ++mask)
    {
        for (int i = 0; i < k; ++i)
            if (f[i][mask] < 2e9)
                for (int j = 0; j < k; ++j)
                {
                    if (((mask >> j) & 1) == 0) f[j][mask|(1 << j)] = min(f[j][mask | (1 << j)], f[i][mask] + a[ki[i]][ki[j]]);
                }
    }
    int res = 2e9;
    for (int i = 0; i < k; ++i) res = min (res, f[i][(1 << k) - 1] + a[ki[i]][1]);
    cout << res;
    return 0;
}