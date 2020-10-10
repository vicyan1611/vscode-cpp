#include <iostream>
using namespace std;
const int Nmax = 1e5 + 5;
int a[Nmax], pricel[Nmax], pricer[Nmax];
int n, m, f[11][Nmax];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        pricel[i] = pricel[i-1] + a[i];
    }
    for (int i = n; i >= 1; --i)
    {
        pricer[i] = pricer[i+1] + a[i]; 
    }
    for (int i = 0 ; i <= m; ++i)
    {
        f[i][i] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        f[1][i] =  pricel[i-1]; 
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = i + 1; k < j; ++k)
            {
                
            }
        }
    }
    return 0;
}