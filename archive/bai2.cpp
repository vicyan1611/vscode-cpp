/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "bai2"
#define endl '\n'
using namespace std;
const int Nmax = 1e5 + 5;
int n, a[Nmax];
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort (1 + a, 1 + a + n);
    int j = n;
    int sums = 0;
    for (int i = n; i >= 1; --i)
    {
        sums += a[i];
        while (j >= 1 && a[j] + k > a[i])
            j--;
        if (j >= 1) sums -= a[j--];
        
    }
    cout << sums << endl;
    return 0;
}