/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "lcm"
#define endl '\n'
using namespace std;
long long lcm(long long x, long long y)
{
    return x * y / __gcd(x, y);
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n;
    cin >> n;
    if (n == 1)
    {
        cout << n;
    } else if (n == 2) cout << n * (n-1); else
    {
        long long base = n * (n - 1);
        long long res = lcm(n, lcm(n - 1, n -2));
        res = max(res, lcm(base, n - 3));
        res = max(res, lcm(base, n/2));
        res = max(res, lcm(base, n/2 + 1));
        res = max(res, lcm(base, n/2 - 1));
        cout << res;
    }
    return 0;
}
