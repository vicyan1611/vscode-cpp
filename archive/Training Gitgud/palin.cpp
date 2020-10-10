/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "palin"
#define endl '\n'
using namespace std;
string st;
int f[5005][5005];
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string st1, st2;
    cin >> st1;
    for (int i = 0; i < st1.size(); ++i)
    {
        st2 = st1[i] + st2;
    }
    st1 = " " + st1;
    st2 = " " + st2;
    int n = st1.size();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            if (st1[i] == st2[j]) f[i][j] = max(f[i-1][j-1] + 1, max(f[i-1][j], f[i][j-1])); else f[i][j] = max(f[i-1][j], f[i][j-1]);
    }
    cout << n - f[n][n];
    return 0;
}