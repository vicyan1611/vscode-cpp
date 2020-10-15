/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "taho2"
#define endl '\n'
using namespace std;
const int Nmax = 45;
int n, s, p;
int a[Nmax];
int sums, money, res = 1e9;
void solve(int i)
{
    if (sums > s) return;
    if (sums == s)
    {
        res = min(res, money);
        return;
    }
    if (i > n)
    {
        if (sums == s) res = min(res, money);
        return;
    }
    for (int j = 0; j <= 1; ++j)
    {
        sums += a[i] * j;
        money += p * j;
        solve(i + 1);
        sums -= a[i] * j;
        money -= p * j;
    }
}
int main()
{
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> s >> p;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(1 + a, 1 + a + n);
    solve(1);
    if (res == 1e9) cout << -1; else cout << res;
    return 0;
}