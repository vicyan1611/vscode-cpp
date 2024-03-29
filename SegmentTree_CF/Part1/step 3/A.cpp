/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "A"
#define endl '\n'
using namespace std;
const int Nmax = 1e5 + 5;
int a[Nmax];
struct segmenttree
{
    int size;
    vector <int> sums;
    void init(int n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        sums.assign(2 * size, 0);
    }
    void update(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            sums[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid)
        {
            update(i, v, x * 2 + 1, lx, mid);
        } else
        {
            update(i, v, x * 2 + 2, mid, rx);
        }
        sums[x] = sums[x * 2 + 1] + sums[x * 2 + 2];
    }
    void update(int i, int v)
    {
        update(i, v, 0, 0, size);
    }
    int calc(int l, int r, int x, int lx, int rx)
    {
        if (rx <= l || lx >= r) return 0;
        if (l <= lx && rx <= r) return sums[x];
        int mid = (lx + rx) / 2;
        int sums1 = calc(l, r, x * 2 + 1, lx, mid);
        int sums2 = calc(l, r, x * 2 + 2, mid, rx);
        return sums1 + sums2;
    }
    int calc(int x, int n)
    {
        return calc(x, n, 0, 0, size);
    }
};
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    segmenttree st;
    st.init(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cout << st.calc(a[i], n) << " ";
        st.update(a[i] - 1, 1);
    }
    return 0;
}