#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
const int Nmax = 1e5 + 5;
int n, a[Nmax];
vector <int> b,c;
int main()
{
    freopen("1401C.inp","r",stdin);
    freopen("1401C.out","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int minn = 1e9;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            minn = min(minn, a[i]);
        }
        b.clear();
        c.clear();
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] % minn == 0)
            {
                b.push_back(a[i]);
                c.push_back(i);
            } 
        }
        sort(b.begin(), b.end());
        bool  kt = true;
        for (int i = 0; i < c.size(); ++i)
        {
            a[c[i]] = b[i];
        }
        for (int i = 1; i < n; ++i)
        {
            if (a[i] > a[i+1]) kt = false;
        }
        if (kt == false) cout << "NO" << endl; else cout << "YES" << endl;
    }
    return 0;
}