#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const int Nmax = 1e5 + 5;
int n, k;
int a[Nmax];
int main()
{
    freopen("bus.inp","r",stdin);
    freopen("bus.out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(1 + a, 1 + a + n);
    int res1, tmp1 = 1e9;
    int res2, tmp2 = 1e9;
    for (int j = 0; j <= k; ++j)
    {
        int tmp_sums = 0;
        int tmp_max = 0;
        for (int i = 1; i <= n; ++i)
        {
            int tmp =  j + (a[i] / k) * k;
            if (tmp < a[i]) tmp += k;
            tmp_sums += tmp - a[i];
            tmp_max = max(tmp_max, tmp - a[i]);
        }
        if (tmp_sums < tmp1)
        {
            res1 = j;
            tmp1 = tmp_sums;
        }
        if (tmp_max < tmp2)
        {
            res2 =  j;
            tmp2 = tmp_max;
        }
    }
    cout << res1 << endl << res2;
    return 0;
}