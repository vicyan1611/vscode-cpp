#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const int Nmax = 1e4 + 5;
int n, x;
int a[Nmax];
int main()
{
    freopen("data.inp","r",stdin);
    freopen("data.out","w",stdout);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(1+a, 1+a+n);
    int i = 1; 
    int j = n;
    int res = 0;
    while (i <= j)
    {
        if (i == j)
        {
            res++;
            break;
        }
        if (a[i] + a[j] <= x)
        {
            res++;
            i++;
            j--;
        } else 
        {
            j--;
            res++;
        }
    }
    cout << res;
    return 0;
}