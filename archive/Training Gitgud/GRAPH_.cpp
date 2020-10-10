#include <iostream>
#include <vector>
using namespace std;
const int Nmax = 1e4 + 5;
int n, m, num_cnt;
int low[Nmax], num[Nmax];
bool bridge[Nmax], point[Nmax];
vector <int> adj[Nmax];
void dfs(int u, int p)
{
    low[u] = num[u] = ++num_cnt;
    int NumChild = 0;

    for (int v: adj[u])
    {
        if (v != p)
        {
            if (num[v] == 0)
            {
                dfs(v, u);
                NumChild++;
                low[u] = min (low[u], low[v]);
                //check bridge
                if (low[v] >= num[v]) bridge[v] = true;
                //check point
                if (u == p)
                {
                    if (NumChild >= 2)
                        point[u] = true;
                } else
                {
                    if (low[v] >= num[u])
                        point[u] = true;
                }
                
            } else
            {
                low [u] = min (low[u], num[v]);
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

    num_cnt=0;
    for (int i = 1; i <= n; i++)
    {
        if (num[i] == 0)
        {
            dfs(i, i);
        }
    }

    int cnt_bridge = 0, cnt_point = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (bridge[i] == true) cnt_bridge++;
        if (point[i] == true) cnt_point++;
    }

    cout << cnt_point << " " << cnt_bridge;

    return 0;
}