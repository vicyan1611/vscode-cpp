/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "guess"
#define endl '\n'
using namespace std;
const int Nmax = 1e5 + 5;
int n, m;
pair <int, string> a[Nmax];
map <string, bool> ma;
int res[Nmax];
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = m; i >= 1; --i)
    {
        if (ma[a[i].second] == false)
        {
            ma[a[i].second] = true;
            res[a[i].first]++;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << res[i] << " ";
    }
    return 0;
}