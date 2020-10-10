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
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        long long res = 0;
        for (int i = 1; i < n; ++i)
        {
            if (a[i] > a[i+1]) res += a[i] - a[i+1];
        }
        cout << res << endl;
    }
    return 0;
}