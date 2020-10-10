#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
const long long Nmax = 1e5 + 5;
const long long oo = 1e18;
pair <long long, long long> line[Nmax], luu[Nmax], pq[Nmax];
double x[Nmax];
long long m = 00;
bool ok(long long u, long long i)
{
    if (line[i].first == luu[u].first) return false;
    if (u == 1) return true;
    double xM = (double) (luu[u].second - line[i].second) / (line[i].first - luu[u].first);
    u--;
    double xN = (double) (luu[u].second - line[i].second) / (line[i].first - luu[u].first);
    return xM > xN;
}
long long bnrs(long long xx)
{
    long long l = 0, r = m, k;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        if (x[mid] == xx) return mid;
        if (x[mid] > xx) r = mid - 1; else
        {
            k = mid;
            l = mid + 1;
        } 
    }
    return k;
}
int main()
{
    freopen("cmin.inp","r",stdin);
    freopen("cmin.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; ++i)
    {
        cin >> line[i].first >> line[i].second;
        line[i].first = -line[i].first;
        line[i].second = -line[i].second;
    }

    sort(1 + line, 1 + line + n);

    for (long long i = 1; i <= n; ++i)
    {
        while (m > 0 && !ok(m, i)) --m;
        luu[++m] = line[i];
    }

    x[0] = -oo; pq[0] = luu[1];
    for (long long i = 1; i < m; ++i)
    {
        x[i] = (double) (luu[i+1].second - luu[i].second) / (luu[i].first - luu[i+1].first);
        pq[i] = luu[i+1];
    }
    x[m] = oo;
    long long q;
    cin >> q;
    while (q--)
    {
        long long z;
        cin >> z;
        long long u = bnrs(z);
        cout << (pq[u].first * z + pq[u].second) * (-1) << endl;
    }
    return 0;
}