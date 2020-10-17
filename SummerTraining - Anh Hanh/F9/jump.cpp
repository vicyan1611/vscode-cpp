/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "jump"
#define endl '\n'
using namespace std;
long long d, t, b;
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> d >> t >> b;
    if (b == 1)
    {
        if (t == d) cout << "Possible"; else cout << "Impossible";
        return 0;
    }
    if ((d - t) % (b - 1) != 0) return cout << "Impossible", 0;
    long long tmp = (d - t) / (b - 1);
    if (tmp < 0) return cout << "Impossible", 0;
    if (tmp > t) return cout << "Impossible", 0;
    cout << "Possible";
    return 0;
}