/*     __//
c   /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <iostream>
#include <fstream>
#include <algorithm>
#define task "1397B"
using namespace std;
const long long Nmax = 1e5 + 5;
long long n, a[Nmax];
int main()
{
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (long long i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    long long x = 1;
    long long res = 1e18;
    bool chec = true;
    while (true)
    {
        long long ans = abs(a[0] - 1);
        long long mul = 1;
        for (long long i = 1; i < n; ++i)
        {
            mul *= x;
            if (mul > 1e10)
            {
                chec = false;
                break;
            } 
            ans += abs(mul - a[i]);
        }
        if (chec == false) break;
        res = min(res, ans);
        x++;
    }
    cout << res;
    return 0;
}