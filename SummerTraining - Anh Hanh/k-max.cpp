#include <iostream>
#include <fstream>
using namespace std;
const long long md = 20102010;
const long long Nmax = 305;
long long n, m, k;
long long a[Nmax][Nmax], f[Nmax][Nmax], d[Nmax][Nmax][105];

int main()
{ 
    freopen("k-max.inp","r",stdin);
    freopen("k-max.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    for (long long i = 1; i <= n; ++i)
        for (long long j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (long long i = 1; i <= n; ++i)
        for (long long j = 1; j <= m; ++j)
            f[i][j] = max(f[i-1][j],f[i][j-1]) + a[i][j];
    cout << f[n][m] << endl;
    d[0][1][0] = 1;
    for (long long i = 1; i <= n; ++i)
    {
        for (long long j = 1; j <= m; ++j)
        {
            long long top, bot;
            if (f[i-1][j] > f[i][j-1])
            {
                top = f[i-1][j] - f[i][j-1]; bot = 0;
            } else
            {
                bot = f[i][j-1] - f[i-1][j]; top = 0;
            }
            for (long long x = 0; x + top <= k; ++x)
            {
                d[i][j][x+top] = (d[i][j][x+top] + d[i][j-1][x]) % md;  
            }
            for (long long y = 0; y + bot <= k; ++y)
            {
                d[i][j][y+bot] = (d[i][j][y+bot] + d[i-1][j][y]) % md;
            }
        }
    }
    long long res = 0;
    for (long long i = 0; i <= k; ++i)
        res = (res + d[n][m][i]) % md;
    cout << res;
    return 0;
}