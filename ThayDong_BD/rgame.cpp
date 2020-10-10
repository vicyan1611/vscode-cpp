/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "rgame"
#define endl '\n'
using namespace std;
const int Nmax = 1e6 + 5;
int n;
double a[Nmax], f[Nmax][2];
double trau(int i, int b)
{
    if (i > n) return 0;
    double &res = f[i][b];
    if (res != -1) return res;
    res = 0;
    if (b == 0)
    {
        res = max(res, max(trau(i + 1, 0) + a[i+1], trau(i + 1, 1)));
    } else if (b == 1)
    {
        res = max(res, max(trau(i + 1, 0) + (a[i-1] + a[i+1]) / 2, trau(i + 1, 1) + a[i-1]));
    }
    return res;
}
void solve()
{
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= 1; ++j)
            f[i][j] = -1;
    }
    f[n][0] = 0;
    f[n][1] = a[n-1];
    printf("%.1lf\n", trau(1, 0));
}
int main()
{
    freopen("rgame.inp","r",stdin);
    freopen("rgame.out","w",stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lf", a + i);
        }
        solve();
    }
    return 0;
}