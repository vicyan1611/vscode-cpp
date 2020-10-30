/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "K"
#define endl '\n'
using namespace std;
const long long Nmax = 105;
const double pi = 3.14159;
long long t, b, n;
struct cautruc
{
    long long s, d;
};
cautruc balls[Nmax];
bool cmp(cautruc a, cautruc b)
{
    if (a.d != b.d) return a.d < b.d;
    return a.s < b.s;
}
int main()
{
  //  freopen(task".inp","r",stdin);
  //  freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t >> b;
    n = b;
    for (long long i = 1; i <= n; ++i)
    {
        cin >> balls[i].s >> balls[i].d;
    }
    sort(1 + balls, 1 + balls + n, cmp);
    long long cnt = 0;
    for (long long i = 1; i <= n; ++i)
    {
        double cv = (double) 2 * pi * balls[i].d;
        long long sl = (long long) t / cv;
        if (sl >= balls[i].s)
        {
            cnt += balls[i].s;
            t -= balls[i].s * cv;
        } else
        {
            cnt += sl;
            t -= sl * cv;
            break;
        }
        if (sl == 0) break;
    }
    cout << cnt;
    return 0;
}
