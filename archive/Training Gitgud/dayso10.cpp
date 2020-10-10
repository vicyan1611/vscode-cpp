/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "dayso10"
#define endl '\n'
using namespace std;
const int Nmax = 3e3 + 5;
int n, a[Nmax], b[Nmax];
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[n-i + 1] = a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
    }
    return 0;
}