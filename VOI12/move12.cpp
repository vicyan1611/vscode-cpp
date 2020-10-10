/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "move12"
#define endl '\n'
using namespace std;
const int Nmax = 1e4 + 5;
int c[Nmax], t[Nmax];
int n;
struct boder
{
    int l, r;
};
boder a[Nmax];
bool cmp1(boder a, boder b)
{
    if (a.l != b.l) return a.l < b.l;
    return a.r < b.r;
}
bool checkk(int v)
{
    for (int i = 1; i <= n; ++i)
    {
        a[i].l = max(1, c[i] - v / t[i]);
        a[i].r = min(n, c[i] + v / t[i]);
    }
    sort(1 + a, 1 + a + n, cmp1);
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    int j = 1;
    for  (int i = 1; i <= n; ++i)
    {
        while (a[j].l <= i && j <= n)
        {
            pq.push({a[j].r, j});
            j++;
        }
        while (!pq.empty() && a[pq.top().second].r < i) pq.pop();
        if (pq.empty()) return false;
        pq.pop();
    }
    return true;
}
int main()
{
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i] >> t[i];
    }
    int res = - 1;
    int l = 0, r = 1e8 + 5;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (checkk(mid) == true)
        {
            res = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << res;
    return 0;
}