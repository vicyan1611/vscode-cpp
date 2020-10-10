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
        sums.resize(2 * size);
    }
    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            sums[x] = v;
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
        sums[x] = sums[x * 2 + 1] + sums[x * 2 + 2];
    }
    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }
    int calc(int k, int x, int lx, int rx)
    {
        if (rx - lx == 1) return lx;
        int mid = (lx + rx) / 2;
        int sl = sums[x * 2 + 1];
        if (sl > k)
        {
            return calc(k, x * 2 + 1, lx, mid);
        } else
        {
            return calc(k - sl, x * 2 + 2, mid, rx);
        }
        
    }
    int calc(int k)
    {
        return calc(k, 0, 0, size);
    }
};
int main()
{
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    segmenttree st;
    cin >> n >> m;
    st.init(n);
    for (int i = 0; i < n; ++i)
    {
        int v;
        cin >> v;
        st.set(i, v);
        a[i] = v;
    }
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int i;
            cin >> i;
            a[i] = 1 - a[i];
            st.set(i, a[i]);
        } else
        {
            int k;
            cin >> k;
            cout << st.calc(k) << endl;
        }
        
    }
    return 0;
}