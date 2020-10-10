#include <iostream>
#include <fstream>
using namespace std;
const int md = 1e9 + 7;
const int Nmax  = 1e5 + 5;
int a[Nmax];
int main()
{
    freopen("andgame.inp","r",stdin);
    freopen("andgame.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    
    return 0;
}