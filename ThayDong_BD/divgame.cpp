/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "divgame"
#define endl '\n'
using namespace std;
const int Nmax = 505;
int f[Nmax][Nmax];
int magic(int x, int y)
{
    if (x == 1 && y == 1) return f[x][y] = 0;
    int &res = f[x][y];
    if (res != -1) return res;
    for (int i = x - 1; i >= 1; --i)
    {
        if (x % i == 0 && magic(i, y) == 0) return res = 1;
    }
    for (int i = y - 1; i >= 1; --i)
    {
        if (y % i == 0 && magic(x, i) == 0) return res = 1;
    }
    for (int i = min(x, y); i > 1; --i)
    {
        if (x % i == 0 && y % i == 0 && magic(x / i, y / i) == 0) return res = 1;
    }
    return res = 0;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x, y;
    cin >> x >> y;
    if (x || y > 500) return cout << "A", 0;
    for (int i = 0; i <= x; ++i)
    {
        for (int j = 0; j <= y; ++j)
            f[i][j] = -1;
    }
    if (magic(x, y) == 1) cout << "A" << endl; else cout << "B" << endl;
    return 0;
}