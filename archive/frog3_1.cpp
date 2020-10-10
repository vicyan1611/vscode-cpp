#include <iostream>
#include <fstream>
using namespace std;
const int Nmax = 1e6 + 5;
int n, c;
int h[Nmax], cost[Nmax];
int main()
{
    freopen("frog.inp","r",stdin);
    cin >> n >> c;
    for (int i = 1; i <= n; ++i)
    {
        cin >> h[i];
    }
    cost[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        cost[i] = 1e9;
        for (int j = 1; j < i; ++j) cost[i] = min(cost[i], (h[j] - h[i]) * (h[j] - h[i]) + c + cost[j]);
        cout << cost[i] << " ";
    }
    cout << cost[n];
    return 0;
}