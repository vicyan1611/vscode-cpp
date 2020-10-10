#include <iostream>
#include <fstream>
using namespace std;
const int Nmax = 30005;
int n, a[Nmax], sumsl[Nmax], sumsr[Nmax];
int main()
{
    freopen("mountain.inp","r",stdin);
    freopen("mountain.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sumsl[i] = sumsl[i-1] + a[i];
    }
    for (int i = n; i >= 1; --i)
    {
        sumsr[i] = sumsr[i+1] + a[i];
    }
    if (n == 1 || n == 0) cout << 0;
    if (n == 2)
    {
        cout << min(a[1], a[2]);
    }
    if (n >= 3 && n < 6)
    {
        int res = 1e9;
        for (int i = 1; i <= n-2; ++i)
        {
            for (int j = i + 2; j <= i+3; ++j)
            {
                if (j <= n)
                {
                    if (j == i + 2)
                    {
                        res = min(res, sumsl[i-1] + sumsr[j+1] + a[i+1]);
                    } else if (j == i+3)
                    {
                        res = min(res, sumsl[i-1] + a[i+1] + a[i+2] + sumsr[j+1]);
                    }
                }
            }
        }
        cout << res << endl;
    }
    if (n >= 6)
    {
        int res = 1e9;
        for (int i = 1; i <= n - 5; ++i)
        {
            int tmp1 = i + 2;
            int tmp2 = i + 5;
            res = min(res, sumsl[i-1] + a[i+1] + a[tmp1+1] + a[tmp2-1] + sumsr[tmp2+1]);
            tmp1 = i + 3;
            tmp2 = i + 5;
            res = min(res, sumsl[i-1] + a[i+1] + a[tmp1-1] + a[tmp2-1] + sumsr[tmp2+1]); 
        }
        cout << res << endl;
    }
    return 0;
}