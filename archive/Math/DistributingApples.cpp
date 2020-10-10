#include <iostream>
using namespace std;
const long long md = 1e9 + 7;
long long n, m;
long long gt[2000006];
long long exp(long long a, long long n)
{
    if (n == 0) return 1;
    if (n == 1) return a;
    long long tmp = exp(a, n/2);
    if (n&1) return (((tmp * tmp) % md) * a) % md;
    return (tmp * tmp) % md;
}
int main()
{
    cin >> n >> m;
    gt[1] = 1;
    gt[0] = 1;
    for (long long i = 2; i <= n + m; ++i)
    {
        gt[i] = (gt[i-1] * i) % md;
    }
    long long tich = (gt[n-1] * gt[m]) % md;
    cout << (gt[n+m-1] * exp(tich, (long long) 1e9 + 5)) % md;
    return 0;
}