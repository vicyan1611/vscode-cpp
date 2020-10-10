#include <iostream>
#include <vector>
using namespace std;
const int Nmax = 1e5 + 5;
bool vis[Nmax];
int col[Nmax];
int n, m;
vector <int> adj[Nmax];

void dfs(int u, int color)
{
    vis[u] = true;
    col[u] = color;
    int new_color;
    if (color == 1)
    {
        new_color = 2;
    } else if (color == 2) 
    {
        new_color = 1;
    }
    for (int v:adj[u])
    {
        if (vis[v] == false) dfs(v, new_color); else
        {
            if (col[v] == color)
            {
                cout << "IMPOSSIBLE";
                exit(0);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i] == false)
            dfs(i, 1);
    }
    for (int i = 1; i <= n; ++i)
        cout << col[i] << " ";
    return 0;
}