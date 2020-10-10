#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int Nmax = 1e5 + 5;
vector <int> adj[Nmax], ress[Nmax];
int n, m, cnt_res;
bool vis[Nmax];
queue <int> q;
void bfs(int s)
{
    vis[s]=true;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        ress[cnt_res].push_back(u);
        q.pop();
        for (int v: adj[u])
        {
            if (vis[v] == false)
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cnt_res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            cnt_res++;
            bfs(i);
        }
    }
    cout << cnt_res << endl;
    for (int i = 1; i <= cnt_res; ++i)
    {
        cout << ress[i].size() <<" ";
        for (int v: ress[i])
            cout << v << " ";
        cout << endl;
    }
    return 0;
}