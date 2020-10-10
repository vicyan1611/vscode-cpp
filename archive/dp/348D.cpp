#include <iostream>
using namespace std;
const long long Nmax = 3005;
const long long md = 1e9 + 7;
long long n, m;
char a[Nmax][Nmax];
long long f[Nmax][Nmax];
long long dem(long long u, long long v, long long x, long long y)
{
    for (long long i = 0; i <= n; ++i)
        for (long long j = 0; j <= m; ++j)
            f[i][j] = 0;
    if(a[u][v] != '#') f[u][v] = 1;
    for (long long i = u; i <= x; ++i)
    {
        for (long long j = v; j <= y; ++j)
        {
            if (a[i][j] == '#')
            {
                f[i][j] = 0;
                continue;
            }
            if (a[i-1][j] == '.')
                f[i][j] = (f[i-1][j] + f[i][j]) % md;
            if (a[i][j-1] == '.')
                f[i][j] = (f[i][j-1] + f[i][j]) % md;
        }
    }
    return f[x][y];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (long long i = 1; i <= n; ++i)
    {
        for (long long j = 1; j <= m; ++j)
            cin >> a[i][j];
    }
    long long p = dem(1, 2, n-1, m);
    long long q = dem(2, 1, n, m-1);
    long long u = dem(1, 2, n, m-1);
    long long v = dem(2, 1, n-1, m);
    cout << ((p * q - u * v) % md + md) % md;
    return 0;
}