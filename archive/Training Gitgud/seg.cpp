/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "seg"
#define endl '\n'
using namespace std;
const int Nmax = 1e3 + 4;
int a[Nmax], f[Nmax];
int n;
bool cnp(int x)
{
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (f[mid] == x) return true;
        if (f[mid] < x) l = mid + 1; else r = mid - 1;
    }
    return false;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        f[i] = f[i-1] + a[i];
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (f[n] % f[i] == 0)
        {
            int x = f[i] * 2;
            bool kt = true;
            while (x < f[n])
            {
                kt = kt & cnp(x);
                x += f[i];
            }
            if (kt) res = max(res, f[n] / f[i]);
        }
    }
    cout << res << endl;
    return 0;
}