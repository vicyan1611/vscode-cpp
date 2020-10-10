/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "costquery"
#define endl '\n'
using namespace std;
const long long Nmax = 1e5 + 5;
struct cautruc
{
    long long u, v, w;
};
long long n, q, cha[Nmax], weight[Nmax], sums[Nmax];

//map <long long, long long> m;
long long m[Nmax];
bool cmp(cautruc a, cautruc b)
{
    return a.w < b.w;
}
cautruc edge[Nmax];
long long get_root(long long u)
{
    if (cha[u] < 0) return u; else return get_root(cha[u]);
}
long long bnrsr(long long x, long long r)
{
    long long l = 1, k = -1;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        if (weight[mid] <= x)
        {
            k = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return k;
}
long long bnrsl(long long x, long long r)
{
    long long l = 1, k = -1;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        if (weight[mid] >= x)
        {
            k = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return k;
}
long long uni(long long u, long long v)
{
    if (cha[u] > cha[v]) swap(u, v);
    long long x = cha[u] + cha[v];
    long long res = cha[u] * cha[v];
    cha[u] = x;
    cha[v] = u;
    return res; 
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (long long i = 1; i < n; ++i)
    {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    for (long long i = 1; i <= n; ++i)
        cha[i] = -1;
    sort(1 + edge, edge + n, cmp);
    long long n_weight = 0;
    for (long long i = 1; i < n; ++i)
    {
        long long u = get_root(edge[i].u);
        long long v = get_root(edge[i].v);
        weight[++n_weight] = edge[i].w;
        m[n_weight] += uni(u, v);
    }
    for (long long i = 1; i < n; ++i)
    {
        sums[i] = sums[i-1] + m[i]; 
       // cout << m[i] << " ";
    }

    while (q--)
    {
        long long l, r;
        cin >> l >> r;

       // long long x = bnrsr(r, n_weight);
        //long long y = bnrsl(l,n_weight);
        int y = lower_bound(weight+1, weight + n, l) - weight;
        int x = upper_bound(weight+1, weight + n, r) - weight;
        x--;
        if (y<=x)
        cout << sums[x] - sums[y-1] << " ";
        else cout<<"0 ";
    }
    return 0;
}