/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "leader"
#define endl '\n'
using namespace std;
const int Nmax = 55;
vector <int> gr[Nmax];
int m, n;
int f[1 << 16][Nmax][Nmax];
int group[Nmax];
int dp (int t, int i, int k)
{
    if (t == (1 << m) - 1) return 0;
    int &res = f[t][i][k];
    if (res != -1) return res;
    res = 0;
    for (int j = 1; j <= m; ++j)
    {
        if (((1 << (j - 1)) & 1) == 1) continue;
        res = max(res, dp((1 << (j - 1)) ^ t, i, j) + group[k]);
    }
    for (int j = 1; j <= m; ++j)
    {
        if (j == i || ((1 << (j - 1)) & 1) == 1) continue;
        res = max(res, dp(t ^ (1 << (i-1)), j, j) + group[k]);
    }
    return res;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
    {
        int num;
        cin >> num;
        group[i] = 0;
        for (int j = 1; j <= num; ++j)
        {
            int x;
            cin >> x;
            gr[i].push_back(x);
            group[i] = max(group[i], x);
        }
    }
    for (int i = 0; i <= 1 << 10; ++i)
    {
        for (int j = 0; j <= 32; ++j)
            for (int z = 0; z <= 32; ++z)
                f[i][j][z] = -1;
    }
    int res = 0;
    for (int i = 1; i <= m; ++i)
    {
        res = max(res, dp(0, i, i));
    }
    cout << res << endl;
    return 0;
}