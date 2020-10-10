#include <iostream>
using namespace std;
const int Nmax = 205;
int n, m;
int a[Nmax], b[Nmax], tmp[Nmax][Nmax];
bool check(int x)
{
    for (int i = 1; i <= n; ++i)
    {
        bool ok = false;
        for (int j = 1; j <= m; ++j)
        {
            if (((a[i]&b[j])|x) == x) ok = true;
            
        }
        if (ok == false) return false;
    }
    return true;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> b[i];
    }
    for (int i = 0; i <= 512; ++i)
    {
        if (check(i))
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}