#include <iostream>
#include <fstream>
using namespace std;
const int Nmax = 205;
int n;
int a[Nmax][Nmax], f[Nmax][Nmax];
int trau(int x, int y)
{
    if (x > n) return (a[y][1]);
    if (y > n) return (a[x][1]);
    int &res = f[x][y];
    if (res != -1) return res;
    int to = max(x, y) + 1;
    res = 1e9;
    res = min (res, trau(x, to) + a[y][to]);
    res = min (res, trau(to, y) + a[x][to]);
    return res;
}
int main()
{
    freopen("disney1.inp","r",stdin);
    freopen("disney1.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    }
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            f[i][j] = -1;
    for (int i = 1; i <= n; ++i)
    {
        a[i][n+1] = a[i][1];
    }
    cout << trau(1, 1);
    return 0;
}