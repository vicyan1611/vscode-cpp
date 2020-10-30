/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "hfamous"
#define endl '\n'
using namespace std;
const long long Nmax = 1e5 + 5;
vector <long long> adj[Nmax];
long long n, m, k;
stack <long long> below;
long long size[Nmax], vis[Nmax];
int main()
{
  //  freopen(task".inp","r",stdin);
  //  freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >>k;
    for (long long i = 1; i <= m; ++i)
    {
        long long x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        size[x]++;
        size[y]++;
        adj[y].push_back(x);
    }

    long long res = n;
    for (long long i = 1; i <= n; ++i)
    {
        if (size[i] < k)
        {
            below.push(i);
            res--;
        }
    }
    while (!below.empty())
    {
        long long u = below.top();
        below.pop();
        for (auto v: adj[u])
        {
            if (size[v] == k)
            {
                below.push(v);
                res--;
            }
            size[v]--;
        }
    }
    cout << res << endl;
    for (long long i = 1; i <= n; ++i)
    {
        if (size[i] >= k) cout << i << " ";
    }
    return 0;
}