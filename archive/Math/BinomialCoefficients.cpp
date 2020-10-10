#include <iostream>
using namespace std;
const long long md = 1e9 + 7;
long long gt[1000005];
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
    long long t;
    cin >> t;
    gt[0] = 1;
    gt[1] = 1;
    for (int i = 2; i <= 1000003; ++i)
        gt[i] = (gt[i-1] * i) % md;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long c = a - b;
        long long tmp = (gt[b] * gt[c]) % md;
        cout << (gt[a] * exp(tmp, (long long) 1e9 + 5)) % md << endl;
    }
    return 0;
}