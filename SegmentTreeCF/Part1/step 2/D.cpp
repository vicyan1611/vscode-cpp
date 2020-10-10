/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "D"
#define endl '\n'
using namespace std;
struct segmenttree
{
    int size;
    vector <int> values;
    void init(int n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        values.assign(size * 2, 0);
    }
    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            values[x] = v;
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
        values[x] = max(values[x * 2 + 1], values[x * 2 + 2]);
    }
    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }
    int calc(int k, int l, int x, int lx, int rx)
    {
        if (values[x] < k) return -1;
        if (rx <= l) return -1;
        if (rx - lx == 1) return lx;
        int mid = (rx + lx) / 2;
        int res = calc(k, l, x * 2 + 1, lx, mid);
        if (res == -1)
        {
            res = calc(k, l, x * 2 + 2, mid, rx);
        }
        return res;
    }
    int calc(int k, int l)
    {
        return calc(k, l, 0, 0, size);
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
            int x, l;
            cin >> x >> l;
            cout << st.calc(x, l) << endl;
        }
    }
    return 0;
}