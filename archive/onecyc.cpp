#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
const int Nmax  = 1e5 + 5;
int n, m;
bool vis[Nmax];
vector <int> adj[Nmax];
int main()
{
    freopen("onecyc.inp","r",stdin);
    freopen("onecyc.out","w",stdout);
    cin >> n >> m; 
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1)
    return 0;
}