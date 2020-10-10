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
struct item
{
    long long seg, pre, suf, sum;
};
struct segmenttree
{
    long long size;
    vector <item> values;
    void init(long long n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        values.resize(size * 2);
    }
    item single(long long v)
    {
        if (v > 0)
            return {v, v, v, v};
        return {0, 0, 0, v};
            
    }
    item neutral = {0, 0, 0, 0};
    item minimum(item a, item b)
    {
        return
        {
            max(a.suf + b.pre, max(a.seg, b.seg)),
            max(a.pre, a.sum + b.pre),
            max(b.suf, b.sum + a.suf),
            a.sum + b.sum
        };
    }
    void set(long long i, long long v, long long x, long long lx, long long rx)
    {
        if (rx - lx == 1)
        {
            values[x] = single(v);
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
        values[x] = minimum(values[x * 2 + 1], values[x * 2 + 2]);
    }
    void set(long long i, long long v)
    {
        set(i, v, 0, 0, size);
    }
    item calc(long long l, long long r, long long x, long long lx, long long rx)
    {
        if (l >= rx || r <= lx ) return neutral;
        if (l <= lx && rx <= r) return values[x];
        long long mid = (lx + rx) / 2;
        item item1 = calc(l, r, x * 2 + 1, lx, mid);
        item item2 = calc(l, r, x * 2 + 2, mid, rx);
        return minimum(item1, item2);
    }
    item calc(long long l, long long r)
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
    for (long long i = 0; i < n; ++i)
    {
        long long v;
        cin >> v;
        st.set(i, v);
    }
    item res;
    res = st.calc(0, n);
    cout << res.seg << endl;
    while (m--)
    {
        long long i, v;
        cin >> i >> v;
        st.set(i, v);
        res = st.calc(0, n);
        cout << res.seg << endl;
    }
    return 0;
}