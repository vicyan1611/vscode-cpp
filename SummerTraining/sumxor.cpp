/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "sumxor"
#define endl '\n'
using namespace std;
const int Nmax = 1e6 + 5;
int t, n, a[Nmax];
vector <pair <int, int>>  queries[Nmax];
int BIT[Nmax], nextt[Nmax], res[Nmax];
void update(int x, int val)
{
    for (; x <= n; x += x & -x)
    {
        BIT[x] = BIT[x] ^ val;
    }
}
void buildnext()
{
    map <int, int> m;
    for (int i = n; i >= 1; --i)
    {
        if (!m.count(a[i])) nextt[i] = n + 1; else nextt[i] = m[a[i]];
        m[a[i]] = i;
    }
}
int gett(int r)
{
    int res = 0;
    for (; r >= 1; r -= r & -r)
    {
        res = res ^ BIT[r];
    }
    return res;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    buildnext();
    int q;
    cin >> q;
    for (int i = 1; i <= q;  ++i)
    {
        int l, r;
        cin >> l >> r;
        queries[l].push_back({r, i});
    }
    for (int l = n; l >= 1; --l)
    {
        update(nextt[l], a[l]);
        for (auto j: queries[l])
        {
            int r = j.first, index = j.second;
            res[index] = gett(r);
        }
    }
    for (int  i = 1; i <= q; ++i)
        cout << res[i] << " ";
    return 0;
}