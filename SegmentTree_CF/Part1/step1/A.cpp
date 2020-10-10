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
struct segmenttree
{
    long long size;
    vector <long long> sums;
    
    void init(long long n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        sums.assign(size * 2, 0);
    }

    void set(long long i, long long v, long long x, long long lx, long long rx)
    {
        if (rx - lx == 1)
        {
            sums[x] = v;
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

    long long sum(long long l, long long r, long long x, long long lx, long long rx)
    {
        if (l >= rx || r <= lx) return 0;
        if (lx >= l && rx <= r) return sums[x];
        long long mid = (lx + rx) / 2;
        long long sums1 = sum(l, r, x * 2 + 1, lx, mid);
        long long sums2 = sum(l, r, x * 2 + 2, mid, rx);
        return sums1 + sums2;
    }

    long long sum(long long l, long long r)
    {
        return sum(l, r, 0, 0, size);
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
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            long long i, v;
            cin >> i >> v;
            st.set(i, v);
        } else
        {
            long long u, v;
            cin >> u >> v;
            cout << st.sum(u, v) << endl;
        }
    }
    return 0;
}