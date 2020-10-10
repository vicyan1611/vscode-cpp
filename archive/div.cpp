#include <iostream>
#include <fstream>
using namespace std;
const int Nmax = 1e3 + 5;
int a[Nmax], sums[Nmax];
int n;
int bnrs(int x)
{
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (sums[mid] == x) return mid;
        if (sums[mid] > x) r = mid - 1; else l = mid + 1;
    }
    return -1;
}
int main()
{
    freopen("div.inp","r",stdin);
    freopen("div.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sums[i] = sums[i-1] + a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (sums[n] % sums[i] == 0)
        {
            bool checkk = true;
            int tmp = sums[i];
            while (tmp < sums[n])
            {
                tmp += sums[i];
                if (bnrs(tmp) != -1) continue;
                checkk = false;
                break;
            }
            if (checkk == true) return cout << sums[n] / sums[i], 0;
        }
    }
    return 0;
}