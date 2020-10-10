#include <iostream>
#include <fstream>
using namespace std;
const int Nmax = 200005;
int n, k;
bool a[Nmax];
int main()
{
    freopen("swap.inp","r",stdin);
    freopen("swap.out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        a[i] = 1;
    int cntt = n;
    int cnts = n;
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        if (x <= n && y > n)
        {
            if (a[x] == 1 && a[y] == 0)
            {
                cntt--;
                cnts--;
            } else if (a[x] == 0 && a[y] == 1)
            {
                cntt++;
                cnts++;
            }
        }
        swap(a[x], a[y]);
        cout << cntt << endl;
    }

    return 0;
}