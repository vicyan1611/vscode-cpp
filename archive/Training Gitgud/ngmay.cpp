/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "ngmay"
#define endl '\n'
using namespace std;
const int Nmax = 505;
int k[Nmax];
pair <int, int> edge[Nmax][Nmax];
priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
bool 
void dijkstra()
{
}
bool checkk(int x)
{

}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> k[i];
    }
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, t, c;
        cin >> u >> v >> t >> c;
        a[u][v] = make_pair(t, c);
        a[v][u] = make_pair(t, c);
    }
    int l = 1, r = 1e9;
    int res = 0;
    dijkstra();
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (checkk(mid) == true)
        {
            res = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << res << endl;
    return 0;
}