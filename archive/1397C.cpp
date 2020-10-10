/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "1397C"
#define endl '\n'
using namespace std;
const long long Nmax = 1e5 + 5;
long long n, a[Nmax];
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (long long i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    cout << 1 << " " << 1 << endl;
    cout << -a[1] << endl;
    a[1] = 0;
    if (n == 1)
    {
        cout << "1 1" << endl << 0 << endl << "1 1" << endl << 0;
        return 0;
    }
    cout << 2 << " " << n << endl;
    for (long long i = 2; i <= n; ++i)
    {
        long long x = a[i] % (n - 1);
        x += x * (n - 1);
        cout << x - a[i] << " ";
        a[i] = x;
    }
    cout << endl;
    cout << 1 << " " << n << endl;
    for (long long i = 1; i <= n; ++i)
        cout << -a[i] << " ";
    return 0;
}