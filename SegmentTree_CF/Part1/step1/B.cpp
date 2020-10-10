/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "B"
#define endl '\n'
#define oo 1e9
using namespace std;
struct segmenttree
{
    int size;
    vector <int> minn;
    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        minn.assign(2 * size, 0);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            minn[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
        {
            set(i, v, x * 2 + 1, lx, m);
        } else
        {
            set(i, v, x * 2 + 2, m, rx);
        }
        minn[x] = min(minn[x * 2 + 1], minn[x * 2 + 2]);
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }
    int calc(int l, int r, int x, int lx, int rx)
    {
        if (l >= rx || r <= lx) return 1e9;
        if (lx >= l && rx <= r) return minn[x];
        int mid = (lx + rx) / 2;
        int minn1 = calc(l, r, x * 2 + 1, lx, mid);
        int minn2 = calc(l, r, x * 2 + 2, mid, rx);
        return min(minn1, minn2); 
    }
    int calc(int l, int r)
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
            cout << st.calc(l, r) << endl;
        }        
    }
    return 0;
}