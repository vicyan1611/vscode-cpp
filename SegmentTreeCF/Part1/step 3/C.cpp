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
const int Nmax = 2e5 + 5;
int a[Nmax];
int f[Nmax];
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
    int calc(int l, int r, int x, int lx, int rx)
    {
        if (rx <= l || lx >= r) return 0;
        if (lx >= l && rx <= r) return sums[x];
        int mid = (lx + rx) / 2;
        int sums1 = calc(l, r, x * 2 + 1, lx, mid);
        int sums2 = calc(l, r, x * 2 + 2, mid, rx);
        return sums1 + sums2;
    }
    int calc(int l, int r)
    {
        return calc(l, r, 0, 0, size);
    }
};
vector <pair <int, int>> res;
bool cmp(pair <int, int> a, pair <int, int> b)
{
    return a.first < b.first;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    n *= 2;
    segmenttree st;
    st.init(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        f[a[i]] = -1;
    }
    
    for (int i = 0; i < n; ++i)
    {
        if (f[a[i]] == - 1) f[a[i]] = i; else
        {
            res.push_back({a[i], st.calc(f[a[i]], i)});
            st.set(f[a[i]], 1);
        }
    }
    sort(res.begin(), res.end(), cmp);
    for (auto v: res)
    {
        cout << v.second << " ";
    }
    return 0;
}