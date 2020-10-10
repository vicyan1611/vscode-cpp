/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "bube"
#define endl '\n'
using namespace std;
const long long Nmax = 1e5 + 5;
long long n, k;
long long a[Nmax];
int main()
{
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (long long i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort (1 + a, 1 + a + n, greater <long long>());
    long long i = 1, j = 2;
    long long res = a[1];
    while (j <= n)
    {
        if (a[i] - a[j] >= k)
        {
            j++;
            i++;
        } else
        {
            res += a[j];
            j++;
        }
    }
    cout << res;
    return 0;
}