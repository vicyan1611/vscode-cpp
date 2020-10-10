#include <iostream>
#include <fstream>
using namespace std;
const int Nmax = 2005;
int n, k, f[5][Nmax][Nmax];
int trau(int i, int pre, int last)
{
    if (last == 0 && i <= k)  return 0;
    if (i > k && last == 0) return 1; 
    if (i > k && last > 0) return 0; 
    int &res = f[i][pre][last];
    if (res != -1) return res;
    res = 0;
    for (int j = pre + 1; j <= last; ++j)
    {
        res += trau(i+1, j, last - j);
    }
    return res;
}
int main()
{
    freopen("candy.inp","r",stdin);
    freopen("candy.out","w",stdout);
    cin >> n >> k;
    for (int i = 0; i <= k; ++i)
    {
        for (int j = 0 ;j <= n; ++j)
            for (int z = 0; z <= n; ++z)
                f[i][j][z] = -1;
    }
    cout << trau(1, 0, n) << endl;
    return 0;
}