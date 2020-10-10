/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "perms"
#define endl '\n'
using namespace std;
int n;
bool vis[10];
int x[10];
void xuat()
{
    for (int i = 1; i <= n; ++i)
    {
        cout << x[i];
    }
    cout << endl;
}
void trau(int i)
{
    for (int j = 1; j <= n; ++j)
    {
        if (vis[j] == false)
        {
            x[i] = j;
            vis[j] = true;
            if (i == n) xuat(); else trau(i + 1);
            vis[j] = false;
        }
    }
}
int main()
{
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int res = 1;
    for (int i = 2; i <= n; ++i)
        res *= i;
    cout << res << endl;
    trau(1);
    return 0;
}