/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "C"
#define endl '\n'
using namespace std;
struct segmenttree
{
    int size;
    vector <pair <int, int>> values;
    void init(int n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        values.resize(2 * size);
    }
    pair <int, int> minimum (pair <int, int> a, pair <int, int> b)
    {
        if (a.first == b.first) return make_pair(a.first, a.second + b.second);
        if (a.first < b.first) return a;
        if (b.first < a.first) return b;
    }
    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            values[x] = make_pair(v, 1);
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid)
        {
            set(i, v, x * 2 + 1, lx, mid);
        } else
        {
            set(i, v, x * 2 + 2, mid, rx);
        }
        values[x] = minimum(values[x * 2 + 1], values[x * 2 + 2]);
    }
    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }
    pair <int, int> calc(int l, int r, int x, int lx, int rx)
    {
        if (rx <= l || lx >= r) return make_pair(1e9, 0);
        if (rx <= r && lx >= l) return values[x];
        int mid = (lx + rx) / 2;
        pair <int, int> tmp1 = calc(l, r, x * 2 + 1, lx, mid);
        pair <int, int> tmp2 = calc(l, r, x * 2 + 2, mid, rx);
        return minimum(tmp1, tmp2);
    }
    pair <int, int> calc(int l, int r)
    {
        return calc(l, r, 0, 0, size);
    }
};
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    segmenttree st;
    st.init(n);
    for (int i = 0; i < n; ++i)
    {
        int v;
        cin >> v;
        st.set(i, v);
    }
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        } else
        {
            int l, r;
            cin >> l >> r;
            pair <int, int> res = st.calc(l, r);
            cout << res.first << " " << res.second << endl;
        }
    }
    return 0;
}