/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "teleport"
#define endl '\n'
using namespace std;
const long long Nmax = 1e5 + 5;
long long n, ne_x[Nmax], pos_x[Nmax], cnt_ne, cnt_pos, sums_pos[Nmax], sums_ne[Nmax];
long long solve_pos(long long i)
{
    long long tmp = sums_pos[i-1];
    long long mid = (cnt_pos + i) / 2;
    if ((cnt_pos - i + 1) & 1)
    {
        tmp += (sums_pos[cnt_pos] - sums_pos[mid]) - (sums_pos[mid-1] - sums_pos[i-1]);
    } else
    {
        tmp += (sums_pos[cnt_pos] - sums_pos[mid]) - (sums_pos[mid] - sums_pos[i-1]);
    }
    return tmp;
}
long long solve_ne(long long i)
{
    long long tmp = sums_ne[i-1];
    long long mid = (cnt_ne + i) / 2;
    if ((cnt_ne - i + 1) & 1)
    {
        tmp += (sums_ne[cnt_ne] - sums_ne[mid]) - (sums_ne[mid-1] - sums_ne[i-1]);
    } else
    {
        tmp += (sums_ne[cnt_ne] - sums_ne[mid]) - (sums_ne[mid] - sums_ne[i-1]);
    }
    return tmp;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    long long res = 1e18;
    for (long long i = 1; i <= n; ++i)
    {
        long long x;
        cin >> x;
        if (x < 0) ne_x[++cnt_ne] = -x; else
        pos_x[++cnt_pos] = x;
    }
    sort(1 + ne_x, 1 + ne_x + cnt_ne);
    sort(1 + pos_x, 1 + pos_x + cnt_pos);
    for (long long i = 1; i <= cnt_pos; ++i)
    {
        sums_pos[i] = sums_pos[i-1] + pos_x[i];
    }
    for (long long i = 1; i <= cnt_ne; ++i)
    {
        sums_ne[i] = sums_ne[i-1] + ne_x[i];
    }
    for (long long i = 1; i <= cnt_pos; ++i)
    {
        long long dis_to_x = solve_pos(i);
        res = min(res, dis_to_x + sums_ne[cnt_ne]);
    }
    for (long long i = 1; i <= cnt_ne; ++i)
    {
        long long dis_to_x = solve_ne(i);
        res = min(res, dis_to_x + sums_pos[cnt_pos]);
    }
    cout << res;
    return 0;
}