/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "numtable"
#define endl '\n'
using namespace std;
const int Nmax = 1e6 + 5;
const int maxValues = 1e7 + 5;
vector <int> table[Nmax];
vector <bool> vis[Nmax];
vector <pair<int, int>> cells[maxValues];
int n, m;
vector <pair <int, int>> primeFactor(int x)
{
    vector <pair <int, int>> res;
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            res.push_back(make_pair(i, 0));
            while (x % i == 0)
            {
                res.back().second++;
                x /= i;
            }
        }
    }
    if (x > 1) res.push_back(make_pair(x, 1));
    return res;
}
bool inside(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int bfs(int i, int j, int d)
{
    queue <pair <int, int>> que;
    vis[i][j] = true;
    que.push(make_pair(i, j));
    int res = 0;
    while (!que.empty())
    {
        int ux = que.front().first;
        int uy = que.front().second;
        que.pop();
        res++;
        for (int z = 0; z < 4; ++z)
        {
            int vx = ux + dx[z];
            int vy = uy + dy[z];
            if (!vis[vx][vy] && inside(vx, vy) && table[vx][vy] % d == 0)
            {
                vis[vx][vy] = true;
                que.push(make_pair(vx, vy));
            }
        }
        cout << 1;
    }
    return res;
}   
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int subtask;
    cin >> subtask;
    cin >> n >> m;
    cout << 1;
    for (int i = 1; i <= n; ++i)
    {
        table[i].assign(m + 1, 0);
        vis[i].assign(m + 1, false);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cin >> table[i][j];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            vector <pair <int, int>> v = primeFactor(table[i][j]);
            for (auto p: v)
            {
                cells[p.first].push_back(make_pair(i, j));
            }
        }
    }
    int res = 1;
    for (int i = 1; i < maxValues; ++i)
    {
        if (cells[i].size() > 0)
        {
            for (auto v: cells[i])
            {
                if (!vis[v.first][v.second])
                    res = max(res, bfs(v.first, v.second, i));
                vis[v.first][v.second] = false;
            }
        }
    }
    cout << res;
    return 0;
}