/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "bai3"
#define endl '\n'
using namespace std;
const int Nmax = 105;
int a[Nmax];
bool f[50005];
bool checkk[50005][102];
int n, sums;
vector <int> adj[50005];
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sums += a[i];
    }
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = sums / 2; j >= a[i]; j--)
        {
            if (f[j-a[i]] == 1)
            {
                f[j] = 1;
                for (int v : adj[j-a[i]])
                {
                    if (v >= n / 2 + 1 ) continue;
                    if (!checkk[j][v+1])
                    {
                        checkk[j][v+1] = true;
                        adj[j].push_back(v + 1);
                    }
                }
                if(j - a[i] == 0)
                    adj[j].push_back(1);
            }
        }
    }
    for(int i = sums / 2; i >= 1; --i)
        if ((f[i]) && (checkk[i][n/2] == 1 || checkk[i][n/2+1] == 1)) return cout << i << " " << sums - i, 0;
    return 0;
}