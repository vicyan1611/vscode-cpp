/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "cross12"
#define endl '\n'
using namespace std;
const long long Nmax = 100005;
long long stt[Nmax], r[Nmax], m, f[Nmax], time_cross[Nmax], n;
long long cal(long long i)
{
    long long x = 0, rx = r[i], time = 0;
    while (x <= m)
    {
        time++;
        x += rx;
        while (stt[x] == 1) x--;
    }
    return time;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (long long i = 1; i <= n; ++i)
        cin >> r[i];
    long long num_broken = 0, num_great = 0;
    for (long long i = 1; i <= m; ++i)
    {
        char x;
        cin >> x;
        stt[i] = x - '0';
    }
    for (long long i = 1; i <= n; ++i)
    {
        time_cross[i] = cal(i);
    }
    sort(1 + time_cross, 1 + time_cross + n);
    f[1] = time_cross[1];
    f[2] = time_cross[2];
    for (long long i = 3; i <= n; ++i)
    {
        long long with_first = time_cross[1] + f[i-1] + time_cross[i];
        long long with_last = time_cross[1] + f[i-2] + time_cross[i] + time_cross[2] * 2;
        f[i] = min(with_first, with_last);
    }
    cout << f[n];
    return 0;
}