/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "skill"
#define endl '\n'
using namespace std;
const long long Nmax = 1e5 + 5;
long long n, A, cf, cm, m;
long long a[Nmax], b[Nmax], sums[Nmax], cnt_max;

bool checkk(long long x)
{
    long long l = 1, r = n, k = 0;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        if (b[mid] < x)
        {
            k = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    if (x * k - sums[k] <= m) return true; else return false;
}

int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> A >> cf >> cm >> m;
    for (long long i = 1; i <= n; ++i)
        cin >> a[i];
    sort(1 + a, 1 + a + n);
    cnt_max = 0;
    long long loc = 0;
    for (long long i = n; i >= 1; --i)
    {
        if (A - a[i] <= m)
        {
            b[i] = A;
            m -= (A - a[i]);
            cnt_max++;
            loc = i;
        } else b[i] = a[i];
    }
    for (long long i = 1; i <= n; ++i)
        sums[i] = sums[i-1] + a[i];
    long long res = 0;
    while (cnt_max >= 0)
    {
        long long l = 0, r = A + 1, k = 0;
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            if (checkk(mid) == true)
            {
                l = mid + 1;
                k = mid;
            } else r = mid - 1;
        }
        res = max(res, cnt_max * cf + cm * k);
        cnt_max--;
        m += A - a[loc];
        b[loc] = a[loc];
        loc++;
    }
    cout << res << endl;
    return 0;
}