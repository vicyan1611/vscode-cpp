/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "TREELINE"
#define endl '\n'
using namespace std;
const int Nmax = 1e5 + 5;
int n, newtree;
int h[Nmax], b[Nmax];
int bnrs(int x)
{
    int l = 1, r = n, k = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (b[mid] >= x)
        {
            k = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return k;
}
int main()
{
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> newtree;
    for (int i = 1; i <= n; ++i)
    {
        cin >> h[i];
        b[i] = 1e9;
    }
    reverse(h + 1, h + 1 + n);
    int res1 = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x = bnrs(h[i]);
        b[i] = h[i];
        if (x == 1) res1++;
    }
    res1++;
    cout << res1 << endl;
    while (cin >> n)
    {
        solve(n);
    }
    
    return 0;
}