#include <iostream>
#include <fstream>
using namespace std;
const int Nmax = 5005;
int n, a[Nmax], b[Nmax], f[Nmax][Nmax];
int main()
{
    freopen("lines.inp","r",stdin);
    freopen("lines.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1; else f[i][j] = max( f[i-1][j], f[i][j-1]);
        }
    }
    cout << f[n][n];
}