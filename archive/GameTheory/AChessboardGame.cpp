#include <iostream>
#include <fstream>
using namespace std;
int f[17][17];
int trau(int x, int y)
{
    if (x < 1 || x > 15 || y < 1 || y >15) return 1;
    int &res = f[x][y];
    if (res != -1) return res;
    res = 1;
    res = min(res, trau(x-2, y-1));
    res = min(res, trau(x-2, y+1));
    res = min(res, trau(x+1, y-2));
    res = min(res, trau(x-1, y-2));
    if (res == 0) return res = 1; else return res = 0;
}
int main()
{
    //freopen("AChessboardGame.inp","r",stdin);
    //freopen("AChessboardGame.out","w",stdout);
    int t;
    cin >> t;
    for (int i = 0; i <= 16; ++i)
    {
        for (int j = 0; j <= 16; ++j)
            f[i][j] = -1;
    }
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if (trau(x, y) == 1) cout << "First" << endl; else cout << "Second" << endl;
    }
    return 0;
}