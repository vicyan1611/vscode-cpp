#include <iostream>
using namespace std;
const int Nmax = 1e5 + 5;
int n;
int a[Nmax], f[Nmax];
int bnrs(int x)
{
    int l = 1, r = n, k = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (f[mid] <= x)
        {
            k = mid;
            l = mid + 1;
        } else  r = mid - 1;
    }
    return k;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        f[i] = -1e9;
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x = bnrs(a[i]);
        res = max(res, n - x +1);
        f[x] = a[i];
    }
    cout << res;
    return 0;
}