/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "three"
#define endl '\n'
using namespace std;
const long long Nmax = 2e5 + 5;
long long n, k;
long long a[Nmax];
map <long long, long long> m1, m2;
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    long long k0 = 1, k1 = k, k2 = k * k;
    for (long long i = 1; i <= n; ++i)
    {
        cin >> a[i];
        m2[a[i]]++;
    }
    long long res = 0;
    for (long long i = 1; i <= n; ++i)
    {
        if (a[i] % k1 != 0)
        {
            m2[a[i]]--;
            m1[a[i]]++;
        } else
        {
            m2[a[i]]--;
            long long b = a[i] / k1;
            long long pre = b * k0;
            long long last = b * k2;
            if (m1.count(pre) == 0 || m2.count(last) == 0) m1[a[i]]++; else
            {
                res += m1[pre] * m2[last];
                m1[a[i]]++;   
            }
        }
    }
    cout << res;
    return 0;
}