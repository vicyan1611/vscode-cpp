#include <iostream>
#include <algorithm>
#include <fstream>
#define oo 1e9;
using namespace std;
const int Nmax = 50005;
struct RENTLAND
{
    int w,l;
};
RENTLAND plot[Nmax];
int n, cost[Nmax], p[Nmax], q[Nmax];
double x[Nmax];
bool cmp(RENTLAND a, RENTLAND b)
{
    if (a.l != b.l) return a.l > b.l;
    return a.w < b.w;
}
int main()
{
    freopen("rentland.inp","r",stdin);
    //freopen("rentland.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> plot[i].w >> plot[i].l;
    } 
    sort(1 + plot, 1 + plot + n, cmp);
    for (int i = 1; i <= n; ++i)
    {
        cost[i] = oo;
        for (int j = 0; j < i; ++j)
            cost[i] = min(cost[i], cost[j] + plot[j+1].l * plot[i].w);
        cout << cost[i] << " ";
    }
    cout << cost[n];
    return 0;
}