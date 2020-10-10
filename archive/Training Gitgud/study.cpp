/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "study"
#define endl '\n'
using namespace std;
int a[105][105], f[105][105];
vector <int> res;
void trace(int n, int m)
{
    if (n < 1) return;
    for (int j = 0; j <= m; ++j)
    {
        if (f[n][m] == f[n-1][m-j] + a[n][j])
        {
            trace(n - 1, m - j);
            res.push_back(j);
            break;
        }
    }
}
int main()
{
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        cin >> a[i][j];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1 ; j <= m; ++j)
        {
            for (int k = 0; k <= j; ++k)
            {
                f[i][j] = max(f[i][j], f[i-1][j-k] + a[i][k]);
            }
        }
    }
    cout << f[n][m] << endl;
    trace(n, m);
    for (auto v: res)
        cout << v << endl;
    return 0;
}