/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "thidau"
#define endl '\n'
using namespace std;
const int Nmax = 105;
int n, k;
int a[Nmax], b[Nmax], f[Nmax], ans;
int trau(int i)
{
    if (i > n) return 0;
    int &res = f[i];
    if (res != -1) return res;
    int j = i + 1;
    res = b[i];
    while (j <= n)
    {
        if (a[j] >= k + a[i])
        {
            res = max (res, trau(j) + b[i]);
        }
        j++;
    }
    ans = max(ans, res);
    return res;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    for (int i = 0; i <= n; ++i)
        f[i] = -1;
    int tmp = trau(0);
    cout << ans;
    return 0;
}