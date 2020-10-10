/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "1397D"
#define endl '\n'
using namespace std;
const int Nmax = 105;
int a[105];
int main()
{
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i]; 
        if (n == 1) cout << "T" << endl; else
        {
            int cnt = 0;
            int maxx = 0;
            for (int i = 1; i <= n; ++i)
            {
                cnt += a[i];
                maxx = max(a[i], maxx);
            }
            if (cnt&1 || maxx > cnt/2) cout << "T" << endl; else cout << "HL" << endl;
        }
        
    }
    return 0;
}