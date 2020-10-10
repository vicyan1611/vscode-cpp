#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
const int Nmax = 1e6 + 5;
int n, a, b, c;
int f[Nmax], t[Nmax], sums[Nmax];
int cal(int k)
{
    return a * k * k + b * k + c;
}
int main()
{
    freopen("commando.inp","r",stdin);
    freopen("commando.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b >> c;
    for (int i = 1; i <= n; ++i)
    {
        cin >> t[i];
        sums[i] = sums[i-1] + t[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        f[i] = cal(sums[i]); 
        for (int j = 0; j < i; ++j)
        {
            f[i] = max(f[i], f[j] + cal(sums[i] - sums[j]));
        }
        cout << f[i] << " ";
    }
    cout << f[n];
    return 0;
}