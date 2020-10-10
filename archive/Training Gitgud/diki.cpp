/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "diki"
#define endl '\n'
using namespace std;
const int Nmax = 1e5 + 5;
int n, m, a[Nmax];
bool bnrs(int x)
{
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == x) return true;
        if (a[mid] < x)
        {
            l = mid + 1;
        } else r = mid - 1;
    }
    return false;
}
int main()
{
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (bnrs(a[i] + m))
        {
            return cout << a[i] << " " << a[i] + m, 0;
        }
    }
    cout << -1;
    return 0;
}