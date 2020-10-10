/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "quacau"
#define endl '\n'
using namespace std;
const int Nmax = 105;
int a[105], f[105];
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(1 + a, 1 + a + n);
    f[1] = a[1];
    f[2] = a[2];
    for (int i = 3; i <= n; ++i)
    {
        int go_with_first = f[i-1] + a[i] + a[1];
        int go_with_last = a[1] + a[i] + f[i-2] + a[2] + a[2];
        f[i] = min(go_with_first, go_with_last);
    }
    cout << f[n];
    return 0;
}