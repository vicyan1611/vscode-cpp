#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const long long Nmax = 2e6 + 5;
const long long md = 1e9 + 7;
const long long base = 27;
string st;
long long res, Pow[Nmax], h[Nmax], n, m;

long long get_Hash(long long i, long long j)
{
    return (h[j] - h[i-1] * Pow[j-i+1] + md * md) %md;
}

long long bnrs(long long s, long long t)
{
    long long l = 1, r = n, k = 0;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        if (get_Hash(s, s + mid - 1) == get_Hash(t, t + mid - 1))
        {
            k = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return k;
}

void solve(long long s)
{
    long long x = bnrs(res, s);
    //cout << st[res+x] << " " << st[s+x] << endl;
    if (st[res + x] > st[s + x]) res = s;
}

int main()
{
    //freopen("MinimalRotation.inp","r",stdin);
   // freopen("MinimalRotation.out","w",stdout);
    cin >> st;
    n = st.size();
    st = st + st;
    m = st.size();
    st = " " + st;
    Pow[0] = 1;
    res = 1;
    for(long long i = 1; i <= m; ++i)
    {
        h[i] = (h[i-1]*base + st[i]) % md;
        Pow[i] = (Pow[i-1] * base) % md;
    }
    for (long long i = 2; i <= n; ++i)
    {
        solve(i);
    }
    for (int i = res; i < n + res; ++i)
    {
        cout << st[i];
    }
    return 0;
}