/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "ctimso"
#define endl '\n'
using namespace std;
long long n, m;

long long cnt(long long x)
{
    long long res = 1e9;
    for (long long i = x; i <= m; i *= x)
    {
        res = min(res, m / i);
    }
    cout << x << " " << res << endl;
    return res;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    long long i = 2;
    long long res = 1e9;
    bool check_plus = true;
    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0) res = min(res, cnt(i));
    }
    cout << res << endl;
    return 0;
}