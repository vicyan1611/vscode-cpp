/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "ds"
#define endl '\n'
using namespace std;
const int Nmax = 1e5 + 5;
int n, k;
vector <int> adj[Nmax];
queue <int> q;
bool vis[Nmax];
vector <int> res;
void bfs(int s)
{
    vis[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v: adj[u])
        {
            if (vis[v] == true) continue;
            vis[v] = true;
            q.push(v);
        }
    }
    for (int i = 1; i <= n; ++i) if (vis[i] == true)
    {
        res.push_back(i);
    }
}
int main()
{
  //  freopen(task".inp","r",stdin);
  //  freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        int num;
        cin >> num;
        for (int j = 1; j <= num; ++j)
        {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }
    bfs(k);
    cout << res.size() << endl;
    for (auto v: res) cout << v << " ";
    return 0;
}