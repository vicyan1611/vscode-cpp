#include <iostream>
#include <fstream>
#define oo 1e15
using namespace std;
const int Nmax = 1e5 + 5;
int a[Nmax], b[Nmax], dp[Nmax];
double x[Nmax];
int n, c;
pair <int, int> pq[Nmax];
bool ok(int u, int i)
{
    if (b[i] == pq[u].first) return false;
    double xM = (double) (dp[i] - pq[u].second) / (pq[u].first - b[i]);
    u--;
    double xN = (double) (dp[i] - pq[u].second) / (pq[u].first - b[i]);
    return xM > xN; 
}
int main()
{
    freopen("dcva.inp","r",stdin);
    freopen("dcva.out","w",stdout);
    cin >> n >> c;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }
    int m = 1;
    dp[1] = c;
    pq[1].first = b[1];
    pq[1].second = dp[1];
    x[1] = -oo;
    int u = 1;
    for (int i = 2; i <= n; ++i)
    {
        while (u <= m && x[u] <= a[i]) ++u;
        --u;
        dp[i] = pq[u].first * a[i] + pq[u].second;
        if (b[i] == pq[m].first && dp[i] >= pq[m].second) continue;
        while (m > 1 && !ok(m,i)) --m;
        if (u > m) u = m;
        if (m == 1 && pq[1].first == b[i]) pq[1].second = dp[i]; else
        {
            pq[++m].first = b[i];
            pq[m].second = dp[i];
            x[m] = (double) (pq[m].second - pq[m-1].second) / (pq[m-1].first - pq[m].first);
        }
    }
    cout << dp[n];
    return 0;
}