/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "findmin"
#define endl '\n'
using namespace std;
const long long Nmax = 1e5 + 5;
long long a[Nmax], b[Nmax], n, m, k;
priority_queue <pair <long long, long long>, vector <pair <long long, long long>>, greater <pair <long long, long long>>> pq;
long long pack(long long i, long long j) {return i * 100005 + j;}
bool unpack(long long s)
{
    long long x = s / 100005;
    long long y = s % 100005;
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;

    for (long long i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (long long j = 1; j <= m; ++j)
        cin >> b[j];

    sort(1 + a, 1 + a + n); sort(1 + b, 1 + b + m);
    for (long long j = 1; j <= n; ++j)
    {
        pq.push({a[j] + b[1], pack(j, 1)});
    }
    while (k--)
    {
        pair <long long, long long> tmp = pq.top();
        cout << tmp.first << endl;
        pq.pop();
        if (unpack(tmp.second + 1))
        {
            long long x = tmp.second / 100005;
            long long y = tmp.second % 100005;
            pq.push({a[x] + b[y + 1], pack(x, y + 1)});
        }
    }
    return 0;
}