/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "game8"
#define endl '\n'
using namespace std;
const long long Nmax = 17;
long long a[Nmax][Nmax], f[Nmax][1 << 17];
long long n;
long long dp(long long i, long long t)
{
    if (i > n) return 0;
    long long &res = f[i][t];
    if (res != -1) return res;
    res = 1e15;
    for (long long j = 1; j <= n; ++j)
    {
        if ((t >> (j - 1)) & 1 == 1) continue;
        res = min(res, dp(i + 1, t ^ (1 << (j - 1))) + a[i][j]);
    }
    return res;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
    long long T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (long long i = 1; i <= n; ++i)
        {
            for (long long j = 1; j <= n; ++j)
            {
                cin >> a[i][j];
            }
        }
        for (long long i = 0; i <= n; ++i)
        {
            for (long long j = 0; j <= (1 << n); ++j)
                f[i][j] = -1;
        }
        cout << dp(1, 0) << endl;
    }
    return 0;
}