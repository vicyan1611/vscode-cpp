#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
const int Nmax = 2e5 + 5;
int n, res = 0, tmp_sums;
vector <int> adj[Nmax];
void dfs(int u, int par)
{
    
}
int main()
{
    freopen("coloring.inp","r",stdin);
    freopen("coloring.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int v;
        cin >> v;
        adj[i].push_back(v);
        adj[v].push_back(i);
    }    
    for (int i = 1; i <= n; ++i)
    {
        tmp_sums = 0;
        dfs(1, 0);
    }
    return 0;
}