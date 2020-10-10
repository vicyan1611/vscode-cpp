#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int Nmax = 1e5 + 5;

int n, m, cnt_num;
int low[Nmax], num[Nmax];
vector <pair <int, int>> adj[Nmax];
vector <int> res;
void dfs(int u, int par)
{
    low[u] = num[u] = ++cnt_num;
    int NumChild = 0;
    for (auto i: adj[u])
    {
        int v = i.first;
        if (v != par)
        {
            if (num[v] == 0)
            {
                dfs(v, u);
                NumChild++;
                low[u] = min(low[u], low[v]);
                
                if (low[v] >= num[v])
                {
                    res.push_back(i.second);
                }
            } else
                low[u] = min (low[u], num[v]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    for (int i = 1; i <= n; ++i)
    {
        if (num[i] == 0)
        {
            dfs(i, i);
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (int v: res)
    {
        cout << v << " " ;
    }
    return 0;
}