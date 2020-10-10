#include <iostream>
#include <fstream>
using namespace std;
const long long Nmax = 1e18 + 5;
const int Kmax = 1e5 + 5;
long long g[Kmax], x[Kmax], y[Kmax];
int main()
{
    freopen("ezrookgame.inp","r",stdin);
    freopen("ezrookgame.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 5;
    while (t--)
    { 
        long long n, m ,k;
        cin >> n >> m >> k;
        for (int i = 1; i <= k; ++i)
            cin >> x[i] >> y[i];
        for (int i = 1; i <= k; ++i)
            g[i] = (x[i] - 1) ^ (y[i] - 1);
        long long res = 0;
        for (int i = 1; i <= k; ++i)
            res = res ^ g[i];
        if (res == 0) cout << "NO" << endl; else cout <<"YES" << endl;
    }
    return 0;
}