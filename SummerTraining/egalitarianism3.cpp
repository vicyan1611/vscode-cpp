/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "egalitarianism3"
#define endl '\n'
using namespace std;

const int Nmax = 55;
int n, d;
vector <pair <int, int>> adj[55];
struct cautruc
{
    int w, type, ver;
};
cautruc edge[Nmax];
bool operator == (cautruc a, cautruc b)
{
    if (a.w == b.w && a.type == b.type) return true; else return false;
}
bool cmp(cautruc a, cautruc b)
{
    if (a.w == b.w) return a.type < b.type;
    return a.w < b.w;
}

void dfs(int u, int par, int type, int dis_u)
{
    edge[++d] = {dis_u, type, u};
    for (auto tmp: adj[u])
    {
        int v = tmp.first;
        int w = tmp.second;
        if (v == par) continue;
        dfs(v, u, type, dis_u + w);
    }
}

int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl << 1;
        return 0;
    }
    for (int i = 1; i < n; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector <int> original, temp, res;
    res.push_back(1);
    res.push_back(2);
    for (int i = 1; i <= n; ++i)
    {
        d = 0;
        int cnt = 0;
        for (auto tmp: adj[i])
        {
            ++cnt;
            dfs(tmp.first, i, cnt, tmp.second);
        }
        sort(1 + edge, 1 + edge + d, cmp);
        for (int j = 1; j <= d; ++j)
        {
            if (edge[j] == edge[j-1]) continue;
            if (edge[j].w != edge[j-1].w)
            {
                if (res.size() < temp.size())
                {
                    res = temp;
                }
                temp = original;
            }
            temp.push_back(edge[j].ver);
        }
    }
    cout << res.size() << endl;
    for (int i: res)
        cout << i << " ";
    return 0;
}