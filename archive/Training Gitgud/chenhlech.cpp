/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "chenhlech"
#define endl '\n'
using namespace std;
const long long Nmax = 1e5 + 5;
long long n, a[Nmax], f[Nmax];
long long solve(long long u, long long v)
{
    long long sums = f[v] - f[u - 1];
    long long pre = f[u - 1];
    long long k = u;
    long long x = (sums + 1) / 2;
    long long l = u, r = v;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        if (f[mid] - pre == x)
        {
            k = mid;
            break;
        }
        if (f[mid] - pre <= x)
        {
            k = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    long long left = f[k] - pre, right = sums - left;
    long long tmp1 = abs(right - left);
    left = f[k + 1] - pre; right = sums - left;
    long long tmp2 = abs(right - left);
    
    left = f[k - 1] - pre; right = sums - left;
    long long tmp3 = abs(right - left);
    return min(tmp1, min(tmp2, tmp3));
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long m;
    cin >> n >> m;
    for (long long i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for(long long i = 1; i <= n; ++i)
    {
        f[i] = f[i-1] + a[i];
    }
    while (m--)
    {
        long long u, v;
        cin >> u >> v;
        cout << solve(u, v) << endl;
    }
    return 0;
}