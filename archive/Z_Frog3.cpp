#include <iostream>
#include <fstream>
using namespace std;
const long long Nmax = 1e6 + 5;
long long n, c, tmpbi, tmpai;
long long p[Nmax], q[Nmax], h[Nmax], cost[Nmax];
double x[Nmax];
bool ok(long long u)
{
    if (p[u] == tmpai) return false;
    double xM = (double) (tmpbi - q[u]) / (p[u] - tmpai);
    u--;
    double xN = (double) (tmpbi - q[u]) / (p[u] - tmpai);
    return xM > xN;

}
int main()
{
    //freopen("frog.inp","r",stdin);
    cin >> n >> c;
    for (long long i = 1; i <= n; ++i)
    {
        cin >> h[i];
    }
    cost[1] = 0;
    x[1] = -1e18;
    p[1] = (-2) * h[1];
    q[1] = h[1] * h[1] + c;
    long long m = 1;
    long long u = 1;
    for (long long i = 2; i <= n; ++i)
    {
        while (u <= m && x[u] <= h[i]) ++ u;
        --u;
        cost[i] = p[u] * h[i] + q[u] + h[i] * h[i];

        tmpbi = h[i] * h[i] + c + cost[i];
        tmpai = (-2) * h[i];
        if (tmpai == p[m] && tmpbi >= q[m]) continue;
        while (m > 1 && !ok(m)) m--;
        if (u > m) u = m;
        if (m == 1 && tmpai == p[1]) q[1] = tmpbi; else
        {
            p[++m] = tmpai;
            q[m] = tmpbi;
            x[m] = (double) (q[m] - q[m-1]) / (p[m-1] - p[m]);
        }
    }
    cout << cost[n];
    return 0;
}