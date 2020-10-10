#include <iostream>
#include <vector>
using namespace std;
const int Nmax = 1e5 + 5;
vector <int> adj[Nmax], res;
int n, m, cnt_num, cnt_res;
int num[Nmax], low[Nmax];
bool point[Nmax];
void dfs(int u, int par)
{
    num[u] = low[u] = ++cnt_num;
    int NumChild = 0;
    for (int v: adj[u])
    {
        if (v != par)
        {
            if (num[v] == 0)
            {
                dfs(v, u);
                NumChild++;
                low[u] = min (low[u], low[v]);

                if (u == par)
                {
                    if (NumChild > 1)
                        point[u] = true; 
                } else
                {
                    if (low[v] >= num[u])
                        point[u] = true;
                }
                
            } else
            {
                low[u] = min (low[u], num[v]);
            }
            
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (num[i] == 0) dfs(i, i);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (point[i] == true)
        {
            ++cnt_res;
            res.push_back(i);
        }
    }
    cout << cnt_res << endl;
    for (int v: res)
    {
        cout << v << " ";
    }
    return 0;
}