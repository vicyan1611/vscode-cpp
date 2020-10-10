#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const long long Nmax = 200005;
long long a[Nmax], w[Nmax];
int main()
{
    //freopen("1369C.inp","r",stdin);
    //freopen("1369C.out","w",stdout);
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        for (long long i = 1; i <= n; ++i)
            cin >> a[i];
        for (long long i = 1; i <= k; ++i)
        {
            cin >> w[i];
        }
        sort(1 + a, 1 + a + n);
        sort(1 + w, 1 + w + k);
        long long res = 0;
        int x = n - k;
        for (long long i = 1; i <= k; ++i)
        {
            res += a[n-i+1];
            if (w[i] == 1) res += a[n-i+1]; else
            {
                res += a[x - w[i] + 2];
                x -= w[i] - 1;
            }
        }
        cout << res << endl;
    }
    return 0;
}