#include <iostream>
using namespace std;
const long long md = 1e9 + 7;
long long Pow(long long a, long long n)
{
    if (n == 0) return 1;
    if (n == 1) return a % md;
    long long tmp = Pow(a, n/2);
    if (n&1) return ((tmp * tmp) % md * a % md) % md;
    return (tmp * tmp) % md;
}
int main()
{
    long long n, k;
    cin >> n >> k;
    if (n == 0) return cout << 0, 0;
    cout << (((Pow(2,k+1) % md) * (n % md)) % md - Pow(2, k) + 1 + 2 * md) % md;
    return 0;
}