#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;
const int Nmax = 1e5 + 5;
struct edge
{
    int u, v;
};
int n, m, cnt_num, cnt_bicon = 0;
int low[Nmax], num[Nmax], parent[Nmax]; 
vector <int> adj[Nmax];
stack <edge> st;
set <int> bicon[Nmax];

void dfs(int u)
{
    low[u] = num[u] = ++cnt_num;
    int NumChild = 0;
    for (int v: adj[u])
    {
        if (v != parent[u])
        {
            if (num[v] == 0)
            {
                st.push(edge{u,v});
                parent[v] = u;
                NumChild++;
                dfs(v);
                low[u] = min (low[u], low[v]);
                if (u == parent[u])
                {
                    if (NumChild > 1)
                    {
                        cnt_bicon++;
                        while (st.top().u != u || st.top().v != v)
                        {
                            bicon[cnt_bicon].insert(st.top().v);
                            bicon[cnt_bicon].insert(st.top().u);
                            st.pop();
                            cout << st.top().u << st.top().v << endl;
                        }
                        bicon[cnt_bicon].insert(st.top().v);
                        bicon[cnt_bicon].insert(st.top().u);
                        st.pop();
                    }
                } else
                {
                    if (low[v] >= num[u])
                    {
                        cnt_bicon++;
                        while (st.top().u != u || st.top().v !=v)
                        {
                            bicon[cnt_bicon].insert(st.top().v);
                            bicon[cnt_bicon].insert(st.top().u);
                            st.pop();
                        }
                        bicon[cnt_bicon].insert(st.top().v);
                        bicon[cnt_bicon].insert(st.top().u);
                        st.pop();
                    }
                }
                
            } else
            {
                low[u] = min(low[u], num[v]);
                if (low[v] < low[u])
                {
                    st.push(edge{u,v});
                } 
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (num[i] == 0)
        {
            parent[i] = i;
            dfs(i);
        }
    }
    cout << cnt_bicon << endl;
    int rem = 0, res = 0;
    for (int i = 1;i <= cnt_bicon; ++i)
    {
        if (res < bicon[i].size())
        {
            rem = i;
            res = bicon[i].size();
        }
    }
    cout << res << endl;
    for (int v: bicon[rem])
    {
        cout << v << " ";
    }
    return 0;
}