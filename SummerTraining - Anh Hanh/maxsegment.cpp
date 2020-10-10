/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "maxsegment"
#define endl '\n'
using namespace std;
const int Nmax = 5e6 + 5;
int a[Nmax];
deque <int> dq;
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int taolao;
    cin >> taolao;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
        while (!dq.empty() && i - dq.front() >= k) dq.pop_front();
        dq.push_back(i);
        if (i >= k) cout << a[dq.front()] << " ";
    }
    return 0;
}