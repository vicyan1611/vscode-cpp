#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;
const int Nmax = 1e5 + 5;
int n, m;
vector <int> adj[Nmax];
bool vis[Nmax], chec[Nmax];
stack <int> st;
void dfs(int u)
{
    vis[u] = true;
    for (int v: adj[u])
    {
        if (vis[v] == false)
            dfs(v); else if (chec[v] == false && vis[v] == true)
            {
                cout << "IMPOSSIBLE";
                exit(0);
            } 
            
    }
    st.push(u);
    chec[u] = true;
}
int main()
{
    //freopen("CourseSchedule.inp","r",stdin);
    //freopen("CourseSchedule.out","w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n ;++i)
    {
        if (vis[i] == false) dfs(i);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}