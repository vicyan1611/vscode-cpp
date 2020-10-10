/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "gnb"
#define endl '\n'
using namespace std;
const int Nmax = 5e3 + 5;
int Mmax = 2 * 1e5 + 1;
int a[Nmax];
pair <bool, int> sums[500005];
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            if (sums[Mmax+a[i] + a[j]].first == false)
            {
                sums[Mmax+a[i]+a[j]].first = true;
                sums[Mmax+a[i] + a[j]].second = j;
            } else
            {
                sums[Mmax+a[i] + a[j]].second = min(sums[Mmax+a[i]+a[j]].second, j);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i - 1; j >= 1; --j)
        {
            if (sums[Mmax+a[i] - a[j]].first == true)
            {
                if (sums[Mmax+a[i] - a[j]].second < i) 
                {
                    res++;
                    break;
                }
            } 
        }
    }
    cout << res << endl;
    return 0;
}