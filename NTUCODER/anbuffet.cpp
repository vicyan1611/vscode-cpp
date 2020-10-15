#include <bits/stdc++.h>

using namespace std;
const long long Nmax = 35;
const long long saMax = 70000;
long long w[Nmax], v[Nmax];
long long n, U, V, w1, v1, cnt_sums1, w2, v2, n1, n2, res = 0;
pair <long long, long long> sums1[saMax];
void save1()
{
    sums1[++cnt_sums1] = {w1, v1};
}
bool cmp(pair <long long, long long> a, pair <long long, long long> b)
{
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}
struct segmenttree
{
    long long size;
    vector <long long> values;
    void init(long long n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        values.assign(size * 2, 0);
    }
    void set(long long i, long long v, long long x, long long lx, long long rx)
    {
        if (rx - lx == 1)
        {
            values[x] = v;
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
        values[x] = max(values[x * 2 + 1], values[x * 2 + 2]);
    }
    void set(long long i, long long v)
    {
        set(i, v, 0, 0, size);
    }
    long long que(long long l, long long r, long long x, long long lx, long long rx)
    {
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return values[x];
        long long mid = (lx + rx) / 2;
        long long res1 = que(l, r, x * 2 + 1, lx, mid);
        long long res2 = que(l, r, x * 2 + 2, mid, rx);
        return max(res1, res2);
    }
    long long que(long long l, long long r)
    {
        return que(l, r, 0, 0, size);
    }
};
segmenttree st;
void bnrgen1(int i)
{
    if (i > n1)
    {
        save1();
        return;
    }
    for (long long j = 0; j <= 1; ++j)
    {
        w1 += w[i] * j;
        v1 += v[i] * j;
        bnrgen1(i + 1);
        w1 -= w[i] * j;
        v1 -= v[i] * j;
    }
}
void solve()
{
    int l = 1, r = cnt_sums1;
    int vt1 = 1;
    if (w2 > V) return;
    long long uu = max(U - w2,(long long) 0);
    long long vv = max(V - w2, (long long)0);
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (sums1[mid].first >= uu)
        {
            vt1 = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    l = 1, r = cnt_sums1; int vt2 = 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (sums1[mid].first <= vv)
        {
            vt2 = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    //cout << uu << " " << vv << " " << w2 << " " << v2 << " " << vt1 << " " << vt2 << " ";
    if (sums1[vt1].first >= uu && sums1[vt2].first <= vv) res = max(res, v2 + st.que(vt1-1, vt2));
    //cout << res << endl;
}
void bnrgen2(int i)
{
    if (i > n2)
    {
        solve();
        return;
    }
    for (int j = 0; j <= 1; ++j)
    {
        w2 += w[i] * j;
        v2 += v[i] * j;
        bnrgen2(i + 1);
        w2 -= w[i] * j;
        v2 -= v[i] * j;
    }
}
int main()
{
    //freopen("anbuffet.inp","r",stdin);
    //freopen("anbuffet.out","w",stdout);
    cin >> n >> U >> V;
    for (int i = 1; i <= n; ++i)
    {
        cin >> w[i] >> v[i];
    }
    n1 = n / 2;
    n2 = n;
    bnrgen1(1);
    st.init(cnt_sums1);
    sort(sums1 + 1, sums1 + 1 + cnt_sums1, cmp);
    for (int i = 1; i <= cnt_sums1; ++i)
    {
        st.set(i - 1, sums1[i].second);
        //cout << sums1[i].second << " ";
    }
    //cout << endl;
    bnrgen2(n1 + 1);
    cout << res;
    return 0;
}