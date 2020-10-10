#include <iostream>
using namespace std;
int n, m;
int a[55][55];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
    return 0;
}