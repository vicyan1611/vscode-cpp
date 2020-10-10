#include <iostream>
using namespace std;
char a[105][105];
int main()
{
    int n, m, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                    cin >> a[i][j];
            }
        }
        int res = 0;
        for (int i = 1; i < n; ++i)
        {
            if (a[i][m] == 'R') res++;
        }
        for (int i = 1; i < m; ++i)
        {
            if (a[n][i] == 'D') res++;
        }
        cout << res << endl;
    }
    return 0;
}