/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "qn"
#define endl '\n'
using namespace std;
bitset <20> bi[1 << 20];
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, del;
    cin >> n >> del;
    bi[1][0] = 1;
    int z = 2;
    for (int y = 1; y < n; ++y)
    {
        for (int i = z, j = z - 1; j >= 0; ++i, --j)
        {
            bi[i] = bi[j];
            bi[i][y] = 1;
        }
        z *= 2;
    }
    for (int i = 1, res; i < z; ++i)
    {
        res = bi[i].to_ulong() ^ del;
        cout << res << endl;
    }
    return 0;
}