/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "xor"
#define endl '\n'
using namespace std;
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long a, n;
    cin >> a >> n;
    if (a % n)
        return cout << 0, 0;
    long long tmp1 = (a / n) * n;
    long long tmp2 = (a / n + 1) * n;
    cout << min(tmp1 ^ a, tmp2 ^ a);
    return 0;
}