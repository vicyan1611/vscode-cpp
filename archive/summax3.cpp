#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
const long long Nmax = 200005;
long long n, a[Nmax], p[Nmax],f[Nmax][2];
vector <pair <long long, long long>> adj[Nmax];
long long trau(long long i, long long take, long long par)
{
    long long &res = f[i][take];
    if (res != -1) return res;
    res = 0;    
    if (take)
    {
        for (auto v:adj[i])
        {
            if (v.first == par) continue;
            res += min(trau(v.first, 0, i), trau(v.first, 1, i));
        }
        res += a[i];
    } else
    if (!take)
    {
        for (auto v:adj[i])
        {
            if (v.first == par) continue;
            res += trau(v.first, 1, i);
        }
    }
    return res;
}
int main()
{
    freopen("summax3.inp","r",stdin);
    freopen("summax3.out","w",stdout);
    cin >> n;
    for (long long i = 1; i <= n; ++i)
    {
        cin >> a[i];
        f[i][1] = -1;
        f[i][0] = -1;
    }
    for (long long i = 1; i <= n; ++i)
    {
        cin >> p[i];
        if (i != 1)
        {
            adj[i].push_back({p[i], a[p[i]]});
            adj[p[i]].push_back({i,a[i]});
        }
    }
    cout << min(trau(1, 1, 0), trau(1, 0, 0));
    return 0;
}