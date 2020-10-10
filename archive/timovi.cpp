/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "timovi"
#define endl '\n'
using namespace std;
const int Nmax = 2e5 + 5;
int n, k, m;
int res[Nmax];
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k >> m;

    if (n * k >= m)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (m >= k)
            {
                cout << k << " ";
                m -= k;
            } else 
            {
                cout << m << " ";
                m = 0;
            }
        }
        return 0;
    } else
    {
        for (int i = 1; i <= n; ++i)
        {
            res[i] = k;
            m -= k;
        }
        int turn = m / ((n - 1) * k);
        for (int i = 2; i < n; ++i)
        {
            res[i] += k * turn;
        }
        if (turn & 1)
        {
            res[1] += k * ((turn + 1) / 2);
            m -= k * ((turn + 1) / 2);
            res[n] += k * (turn / 2);
            m -= k * (turn / 2);
            for (int i = 2; i <= n; ++i)
            {
                if (m >= k)
                {
                    res[i] += k;
                    m -= k;
                } else
                {
                    res[i] += m;
                    m = 0;
                }
                if (m <= 0) break;
            }
        } else
        {
            res[1] += k * (turn / 2);
            m -= k * (turn / 2);
            res[n] += k * (turn / 2);
            m -= k * (turn / 2);
            for (int i = n - 1; i > 1; --i)
            {
                if (m >= k)
                {
                    res[i] += k;
                    m -= k;
                } else
                {
                    res[i] += m;
                    m = 0;
                }
                if (m <= 0) break;
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << res[i] << " ";
    return 0;
}