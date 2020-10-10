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
        sums.assign(2 * size, 0);
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
    int find(int k, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            return lx;
        }
        int mid = (lx + rx) / 2;
        int res = 0;
        if (sums[x * 2 + 1] > k)
        {
            res = find(k, x * 2 + 1, lx, mid);
        } else
        {
            res = find(k - sums[x * 2 + 1], x * 2 + 2, mid, rx);
        }
        return res;
    }
    int find(int k)
    {
        return find(k, 0, 0, size);
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
    vector <int> res;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        st.set(i, 1);
    }
    for (int i = n - 1; i >= 0; --i)
    {
        int x = n - st.find(a[i]);
        res.push_back(x);
        st.set(n - x, 0);
    }
    reverse(res.begin(), res.end());
    for (auto v: res)
    {
        cout << v << " ";
    }
    return 0;
}