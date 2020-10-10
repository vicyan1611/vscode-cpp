#include <iostream>
#include <fstream>
using namespace std;
const long long Nmax = 1e6 + 5;
long long n, a, b, c;
long long f[Nmax], sums[Nmax], tmpai, tmpbi;
double x[Nmax], p[Nmax], q[Nmax];
bool ok(long long u)
{
    if (p[u] == tmpai) return false;
    double xM = (double) (tmpbi - q[u]) / (p[u] - tmpai);
    u--;
    double xN = (double) (tmpbi - q[u]) / (p[u] - tmpai);
    return (xM > xN);
}
int main()
{
    freopen("commando.inp","r",stdin);
    freopen("commando.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b >> c;
    for (long long i = 1; i <= n; ++i)
    {
        long long tmp;
        cin >> tmp;
        sums[i] = tmp + sums[i-1];
    }
    x[0] = -1e9;
    p[0] = 0;
    q[0] = c;
    long long u = 0;
    long long m = 0;
    for (long long i = 1; i <= n; ++i)
    {
        while (u <= m && x[u] <= sums[i]) u++;
        if (u > 0) u--;
        f[i] = p[u] * sums[i] + q[u] + b * sums[i] + a * sums[i] * sums[i];
        // cout <<x[u] << " " << p[u] << " " << q[u] << " " << f[i] << endl;
        tmpai = (-2) * a * sums[i];
        tmpbi = a * sums[i] * sums[i] - (b * sums[i]) + c + f[i];
        while (m > 0 && !ok(m)) m--;
        if (u > m) u = m;
        if (m == 0 && p[0] == tmpai) q[0] = tmpbi; else
        {
            p[++m] = tmpai;
            q[m] = tmpbi;
            x[m] = double (q[m] - q[m-1]) / (p[m-1] - p[m]);
        }
    }
    cout << f[n];
    return 0;
}