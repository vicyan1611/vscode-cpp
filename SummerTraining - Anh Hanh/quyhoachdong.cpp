/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "quyhoachdong"
#define endl '\n'
using namespace std;
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b, c, m;
    while(cin >> a)
    {
        cin >> b >> c >> m;
        if (a + b + c >= m && a > 0 && b > 0 && c > 0 && m > 2) cout << "No" << " "; else cout << "Yes" << " ";
    }
    return 0;
}