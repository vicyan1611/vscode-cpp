#include <iostream>
using namespace std;
const long long Nmax = 2005;
long long n, h, l, r;
long long a[Nmax], f[Nmax][Nmax];
bool checktime(long long hour)
{
    if (hour >= l && hour <= r) return true; else return false;
}
long long trau(long long i, long long last)
{
    if (i > n) return 0;
    long long &res = f[i][last];
    if (res != -1) return res;
    res = 0;
    long long time1 = (a[i] + last) % h;
    long long time2 = (a[i] - 1 + last) % h;
    res = max(res, trau(i + 1, time1) + checktime(time1));
    res = max(res, trau(i + 1, time2) + checktime(time2));
    return res;
}
int main()
{
    cin >> n >> h >> l >> r;
    for (long long i = 1; i <= n; ++i)
        cin >> a[i];
    for (long long i = 0; i <= n; ++i)
        for (long long j = 0; j <= 2002; ++j)
            f[i][j] = -1;
    cout << trau(1, 0);
    return 0;
}