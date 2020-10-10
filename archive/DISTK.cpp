#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
const int Nmax = 50005;
long long dis[Nmax][205], res, n, k;
vector <int> adj[Nmax];
void dfs(int u, int par)
{
    dis[u][0]++;
    for (int v: adj[u])
    {
        if (v == par) continue;
        dfs(v,u);
        for (int i = 0; i < k; ++i)
            res += dis[u][i] * dis[v][k-i-1];
        for (int i = 0; i < k; ++i)
            dis[u][i+1] += dis[v][i];
    }
}
int main()
{
    freopen("DISTK.inp","r",stdin);
    freopen("DISTK.out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        if (i != 1)
        {
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
    }
    dfs(1,0);
    cout<<res;
    return 0;
}