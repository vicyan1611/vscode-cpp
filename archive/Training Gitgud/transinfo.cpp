/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "transinfo"
#define endl '\n'
using namespace std;
const int Nmax = 1e5 + 5;
vector <int> adj[Nmax];
vector <pair<int, int>> res;
int n;
bool vis[Nmax];
bool in[Nmax], out[Nmax];
vector <int> need_in;
vector <int> need_out;
void dfs(int u)
{
    vis[u] = true;
    for (int v: adj[u])
    {
        out[u] = true;
        in[v] = true;
        if (vis[v] == false)
        {
            dfs(v);
        }
    }
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int v;
        cin >> v;
        if (v != i) adj[i].push_back(v);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i] == false)
        {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (in[i] == false) need_in.push_back(i);
        if (out[i] == false) need_out.push_back(i);
    }
    sort(need_out.begin(), need_out.end(), greater<int>());
    sort(need_in.begin(), need_in.end());
    for (int i = 0; i < min(need_out.size(),need_in.size()); i++)
    {
        if (need_in[i] != need_out[i])
        {
            res.push_back({need_out[i], need_in[i]});
        } else
        {
            for (int j = 1; j <= n; ++j)
            {
                if (j != need_in[i])
                {
                    res.push_back({j, need_in[i]});
                    res.push_back({need_out[i], j});
                    break;
                }
            }
        }
    }
    if (need_in.size() == need_out.size())
    {
        cout << res.size() << endl;
        for (auto v: res)
        {
            cout << v.first << " " << v.second << endl;
        }
        return 0;
    }
    if (need_in.size() < need_out.size())
    {
        for (int i = need_in.size(); i < need_out.size(); ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (j != need_out[i])
                {
                    res.push_back({need_out[i], j});
                }
            }
        }
    } else
    {
        for (int i = need_out.size(); i < need_in.size(); ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (j != need_in[i])
                {
                    res.push_back({j, need_in[i]});
                }
            }
        }
    }
    cout << res.size() << endl;
    for (auto v: res)
    {
        cout << v.first << " " << v.second << endl;
    }
    return 0;
}