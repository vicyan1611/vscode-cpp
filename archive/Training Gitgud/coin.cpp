/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "coin"
#define endl '\n'
using namespace std;
int a[17][17], f[17][17], x[17];
int n = 16, res = 200;
void checkk()
{
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = 1; j <= 4; ++j)
            f[i][j] =  a[i][j];
    }
    int cnt1 = 0;
    for (int i = 1; i <= 16; ++i)
    {
        if (x[i] == 0) continue;
        cnt1++;
        int r = (i - 1) / 4 + 1;
        int c = (i % 4 == 0) ? 4 : i % 4;
        f[r][c] = f[r][c] ^ 1;
        f[r-1][c] = f[r-1][c] ^ 1;        f[r+1][c] = f[r+1][c] ^ 1;        f[r][c-1] = f[r][c-1] ^ 1;       f[r][c+1] = f[r][c+1] ^ 1;
    }
    int fir = f[1][1];
    bool ok = true;
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = 1; j <= 4; ++j)
        {
            if (f[i][j] != fir) ok = false;
        }
    }
    if (ok == true) res = min(res, cnt1);
}
void trau(int i)
{
    for (int j = 0; j <= 1; ++j)
    {
        x[i] = j;
        if (i < n) trau(i + 1); else checkk();
    }
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    res = 200;
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= 4; ++j)
        {
            char ch;
            cin >> ch;
            if (ch == 'w') a[i][j] = 0; else a[i][j] = 1;
        }
    trau(1);
    if (res == 200) cout << "Impossible"; else cout << res;
    return 0;
}