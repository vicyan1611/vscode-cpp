#include <iostream>
#include <stack>
#include <fstream>
using namespace std;
const int Nmax = 2e5 + 5;
int n, a[Nmax];
bool f[Nmax][7];
int trace[Nmax][7];
stack <int> res;
int main()
{
    //freopen("1032C.inp","r",stdin);
    //freopen("1032C.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= 5; ++i)
    {
        f[1][i] = true;
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            if (a[i] > a[i-1])
            {
                for (int z = 1; z < j; ++z)
                    if (f[i-1][z] == true)
                    {
                        f[i][j] = true;
                        trace[i][j] = z;
                    }
            } else if (a[i] < a[i-1])
            {
                for (int z = j + 1; z <= 5; ++z)
                    if (f[i-1][z] == true)
                    {
                        f[i][j] = true;
                        trace[i][j] = z;
                    }
            } else if (a[i] == a[i-1])
            {
                for (int z = 1; z <= 5; ++z)
                    if (z != j)
                        if (f[i-1][z] == true)
                        {
                            f[i][j] = true;
                            trace[i][j] = z;
                        }
            }
        }
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= n; ++j)
    //         cout << trace[i][j]
    // }
    bool chec = false;
    for (int i = 1; i <= 5; ++i)
    {
        chec = max(chec, f[n][i]);
    }
    if (chec == 0) cout << -1; else
    {
        int i = n;
        int x = - 1;
        for (int j = 1; j <=  5; ++j)
        {
            if (f[n][j] == true) x = j;
        }
        while (i >= 1)
        {
            res.push(x);
            x = trace[i][x];
            i--;
        }
        while (!res.empty())
        {
            cout << res.top() << " ";
            res.pop();
        }
    }
    return 0;
}