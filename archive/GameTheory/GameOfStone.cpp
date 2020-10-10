#include <iostream>
#include <fstream>
using namespace std;
const int Nmax = 1e2 + 5;
int f[Nmax];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        f[0] = 0;
        f[1] = 0;
        f[2] = 1;
        f[3] = 1;
        f[4] = 1;
        f[5] = 1;
        for (int i = 6; i <= n; ++i)
        {
            if (f[i-2] == 0 || f[i-3] == 0 || f[i-5] == 0) f[i] = 1; else f[i] = 0;
        }
        if (f[n] == 1) cout << "First" << endl; else cout << "Second" << endl;
    }
    return 0;
}