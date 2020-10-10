#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int Nmax = 1e5 + 5;
int n, m, s, t, trace[Nmax];
vector <int> adj[Nmax];
stack <int> res;
void output()
{
    while (t != 0)
    {
        res.push(t);
        t = trace[t];
    }
    while (!res.empty())
    {
        cout << res.top()<<" ";
        res.pop();
    }
}
void dfs (int u, int par)
{
    trace[u] = par;
    if (u == t)
    {
        output();
        exit (0);
    }
    for (int i: adj[u])
    {
        if (trace[i] != -1) continue;
        dfs(i,u);
    }
}
int main()
{
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 0; i <= n; i++)
    {
        trace[i]=-1;
        sort(adj[i].begin(), adj[i].end());
    }
    
    dfs(s, 0);
    return 0;
}