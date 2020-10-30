/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "spiral"
#define endl '\n'
using namespace std;
const int Nmax = 1e3 + 5;
int n;
int a[Nmax][Nmax];
void create()
{
    int cnt = 0;
    int h = 1;
    while (h <= n / 2)
    {
        for (int i = h; i <= n - h; ++i)
        {
            a[h][i] = ++cnt;
        }   
        for (int i = h; i <= n - h; ++i)
        {
            a[i][n - h + 1] = ++cnt;
        }
        for (int i = n - h + 1; i > h; --i)
        {
            a[n - h + 1][i] = ++cnt;
        }
        for (int i = n - h + 1; i > h; i--)
        {
            a[i][h] = ++cnt;
        }
        h++;
    }
    if (n & 1) a[(n+1) / 2][(n + 1) / 2] = ++cnt;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> n >> x >> y;
        create();
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
                cout << a[i][j] << " ";
            cout << endl;
        }
            
    }
    return 0;
}