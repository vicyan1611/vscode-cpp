#include <iostream>
using namespace std;
const int Nmax = 200005;
int a[Nmax];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long k;
        cin >> n >> k;
        int maxx = -1e9;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            maxx = max(maxx, a[i]);
        }
        if (k&1)
        {
            for (int i = 1; i <= n; ++i)
            {
                cout << maxx - a[i] << " ";
            }
        } else
        {
            int tmpmax = -1e9;
            for (int i = 1; i <= n; ++i)
            {
                a[i] = maxx - a[i];
                tmpmax = max(tmpmax, a[i]);
            }
            for (int i = 1; i <= n; ++i)
            {
                cout << tmpmax - a[i] << " ";
            }
        }
        cout << endl;

    }
    return 0;
}