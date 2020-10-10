/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "E"
#define endl '\n'
using namespace std;
const long long Nmax = 1e5 + 5;
long long a[Nmax];
struct segmenttree
{
    long long size;
    vector <long long> sums;
    void init(long long n)
    {
        size = 1;
        while (size <= n)
            size *= 2;
        sums.assign(2 * size, 0);
    }
    void set(long long i, long long v, long long x, long long lx, long long rx)
    {
        if (rx - lx == 1)
        {
            sums[x] += v;
            return;
        }
        long long mid = (lx + rx) / 2;
        if (i < mid)
        {
            set(i, v, x * 2 + 1, lx, mid);
        } else
        {
            set(i, v, x * 2 + 2, mid, rx);
        }
        sums[x] = sums[x * 2 + 1] + sums[x * 2 + 2];
    }
    void set(long long i, long long v)
    {
        set(i, v, 0, 0, size);
    }
    long long calc(long long l, long long r, long long x, long long lx, long long rx)
    {
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return sums[x];
        long long mid = (lx + rx) / 2;
        long long sums1 = calc(l, r, x * 2 + 1, lx, mid);
        long long sums2 = calc(l, r, x * 2 + 2, mid, rx);
        return sums1 + sums2;
    }
    long long calc(long long l, long long r)
    {
        return calc(l, r, 0, 0, size);
    }
};
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n, m;
    cin >> n >> m;
    segmenttree st;
    st.init(n);
    while (m--)
    {
        long long op;
        cin >> op;
        if (op == 1)
        {
            long long l, r, v;
            cin >> l >> r >> v;
            st.set(l, v);
            st.set(r, (-v));
        } else
        {
            long long i;
            cin >> i;
            cout << st.calc(0, i + 1) << endl;
        }
    }
    return 0;
}