/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "bst"
#define endl '\n'
using namespace std;
int n, h;
const int Nmax = 1e5 + 5;
int sums_node[Nmax];
vector <int> res;
void build(int w, int x, int lx, int rx)
{
    if (lx == rx)
    {
        cout << lx << " ";
        return;
    }
    int to_right = min(sums_node[h - x], w - 1);
    cout << rx - to_right << " ";
    if (rx - to_right > lx)
    {
        build(rx - to_right - 1 - lx + 1, x + 1, lx, rx - to_right - 1);
    }
    build(to_right, x + 1, rx - to_right + 1, rx);
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> h;
    sums_node[1] = 1;
    for (int i = 2; i <= h; ++i)
    {
        sums_node[i] = sums_node[i-1] * 2 + 1;
    }
    if (sums_node[h] < n)
    {
        cout << -1;
        return 0;
    }
    build(n, 1, 1, n);
    return 0;
}