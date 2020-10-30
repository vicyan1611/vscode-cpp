/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "102470A"
#define endl '\n'
using namespace std;
const int Nmax = 50005;
struct xy
{
    int x, y;
};
xy toado[Nmax];
void enter()
{
    for (int i = 1; i <= n; ++i)
    {
        cin >> toado[i].x >> toado[i].y;
    }
    
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while (cin >> n)
    {
        if (n == 0) return 0;
        enter();
    }
    return 0;
}