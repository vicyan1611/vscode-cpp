#include <iostream>
#include <algorithm>
#include <fstream>
#define oo 1e18;
using namespace std;
const long long Nmax = 50005;
struct RENTLAND
{
    long long w,l;
};
RENTLAND plot[Nmax];
long long n, cost[Nmax], p[Nmax], q[Nmax];
double x[Nmax];
bool cmp(RENTLAND a, RENTLAND b)
{
    if (a.l != b.l) return a.l > b.l;
    return a.w < b.w;
}
bool ok(long long u, long long i)
{
    if (p[u] == plot[i+1].l) return false;
    double xM = (double) (cost[i] - q[u]) / (p[u] - plot[i+1].l);
    u--;
    double xN = (double) (cost[i] - q[u]) / (p[u] - plot[i+1].l);
    return xM > xN;
}
int main()
{
    freopen("rentland.inp","r",stdin);
    freopen("rentland.out","w",stdout);
    cin >> n;
    for (long long i = 1; i <= n; ++i)
    {
        cin >> plot[i].w >> plot[i].l;
    } 
    sort(1 + plot, 1 + plot + n, cmp);
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (plot[i].w > plot[cnt].w) plot[++cnt] = plot[i];
    }
    n = cnt;
    cost[0] = 0;
    x[0] = -oo;
    p[0] = plot[1].l;
    q[0] = 0;
    long long m = 0;
    long long u = 0;
    for (long long i = 1; i <= n; ++i)
    {
        while (u <= m && x[u] <= plot[i].w) ++u;
        if (u > 0) --u;
        cost[i] = p[u] * plot[i].w + q[u];
        if (i < n)
        {
            if (p[m] == plot[i+1].l && cost[i] >= q[m]) continue;
            while (m > 0 && !ok(m,i)) m--;
            if (u > m) u = m;
            if (m == 0 && p[0]  == plot[i+1].l) q[0] = cost[i]; else
            {
                p[++m] = plot[i+1].l;
                q[m] = cost[i];
                x[m] = (double) (q[m] - q[m-1]) / (p[m-1] - p[m]);
            }
        }
        
    }
    cout << cost[n];
    return 0;
}