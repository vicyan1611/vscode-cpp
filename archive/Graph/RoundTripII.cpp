#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;
const int Nmax = 1e5 + 5;
vector <int> adj[Nmax];
int n, m;
int vis[Nmax], trace[Nmax];
stack <int> st;
void dfs(int u)
{
    vis[u] = 1;
    for (int v: adj[u])
    {
        if (vis[v] == 0)
        {
            trace[v] = u;
            dfs(v);
        } else if(vis[v] == 1)
        {
            int tmp = u;
            while (tmp != v)
            {
                st.push(tmp);
                tmp = trace[tmp];
            }
            cout << st.size() + 2 << endl;
            cout << v << " ";
            while (!st.empty())
            {
                cout << st.top() << " ";
                st.pop();
            }
            cout << v;
            exit(0);
        }
    }
    vis[u] = 2;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i] == false)
        {
            dfs(i);
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}