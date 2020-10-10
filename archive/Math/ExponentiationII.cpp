#include <iostream>
using namespace std;
const long long m = 1e9 + 7;
long long exp(long long a, long long n, long long md)
{
    if (n == 1) return a;
    if (n == 0) return 1;
    long long tmp = exp(a, n / 2, md);
    if (n&1) return ((tmp * tmp) % md * a) % md;
    return (tmp * tmp) % md;
}
int main()
{
    long long n;
    cin >> n;
    while (n--)
    {
        long long a, b, c; 
        cin >> a >> b >> c;
        long long tmp = exp(b, c, m - 1);
        cout << exp(a, tmp, m) << endl;
    }
    return 0;
}