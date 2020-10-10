#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const int Nmax = 205;
int R, G, B, r[Nmax], g[Nmax], b[Nmax];
long long way[5], f[Nmax][Nmax][Nmax];
int main()
{
    //freopen("1398D.inp","r",stdin);
    //freopen("1398D.out","w",stdout);
    cin >> R >> G >> B;
    for (int i = 1; i <= R; ++i)
    {
        cin >> r[i];
    }
    for (int i = 1; i <= G; ++i)
    {
        cin >> g[i];
    }
    for (int i = 1; i <= B; ++i)
    {
        cin >> b[i];
    }
    sort(1 + r, 1 + r + R, greater <int> ());
    sort(1 + g, 1 + g + G, greater <int> ());
    sort(1 + b, 1 + b + B, greater <int> ());
    f[1][1][0] = r[1] * g[1];
    f[1][0][1] = r[1] * b[1];
    f[0][1][1] = g[1] * b[1];
    for (int x = 0; x <= R; ++x)
        for (int y = 0; y <= G; ++y)
            for (int z = 0; z <= B; ++z)
            {
                if (y - 1 >= 0 && z - 1 >= 0) way[1] = f[x][y-1][z-1] + g[y] * b[z]; else way[1] = 0;
                if (x - 1 >= 0 && z - 1 >= 0) way[2] = f[x-1][y][z-1] + r[x] * b[z]; else way[2] = 0;
                if (x - 1 >= 0 && y - 1 >= 0) way[3] = f[x-1][y-1][z] + r[x] * g[y]; else way[3] = 0;
                way[4] = max(f[max(0, x - 1)][y][z], max(f[x][max(0, y - 1)][z], f[x][y][max(0, z - 1)])); 
                for (int i = 1; i <= 4; ++i)
                    f[x][y][z] = max(f[x][y][z], way[i]);
            }
    cout << f[R][G][B];
    return 0;
}