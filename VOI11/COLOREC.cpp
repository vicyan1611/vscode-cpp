/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "COLOREC"
#define endl '\n'
using namespace std;
const int Nmax = 1e5 + 5;
struct cautruc
{
    int x, y, color;
};
cautruc point[Nmax];
int n;
vector <pair <int, int>> toadox[403],  toadoy[403];
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x,  y, c;
        cin >> x >> y >> c;
        cin >> point[i].x >> point[i].y >> point[i].color;
    }
    return 0;
}