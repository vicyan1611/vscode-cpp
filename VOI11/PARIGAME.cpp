/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "PARIGAME"
#define endl '\n'
using namespace std;
const int Nmax = 505;
int a[Nmax][Nmax], sums_r[Nmax][Nmax], sums_c[Nmax][Nmax], n, f[Nmax][Nmax][3];
bool trau(int i, int j, int turn)
{
    if (i < 1 || j < 1) return false;
    int &res = f[i][j][turn];
    if (res != -1) return res;
    res = 0;
    if (turn == 1)
    {
        if (sums_r[i][j] % 2 == 0)
            res = trau(i - 1, j, 2) ? 0 : 1; 
        if (res == 1) return res;
        if (sums_c[i][j] % 2 == 0)
            res = trau(i, j - 1, 2) ? 0 : 1;
    } else
    {
        if (sums_r[i][j] % 2 == 0)
            res = trau(i - 1, j, 1) ? 0 : 1; 
        if (res == 1) return res;
        if (sums_c[i][j] % 2 == 0)
            res = trau(i, j - 1, 1) ? 0 : 1;
    }
    //cout << i << " " << j << " " << " " << turn << " " << res << endl;
    return res;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
                cin >> a[i][j];
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j) sums_r[i][j] = sums_r[i][j-1] + a[i][j]; 
        }
        for (int j = 1; j <= n; ++j)
        {
            for (int i = 1; i <= n; ++i)
            {
                sums_c[i][j] = sums_c[i-1][j] + a[i][j];
            }
        }
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                f[i][j][1] = f[i][j][2] = f[i][j][0] = -1;
            }
        }
        if (trau(n, n, 1)) cout << "YES" << endl; else cout << "NO" << endl;
    }
    return 0;
}