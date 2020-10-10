#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int Nmax = 1e5 + 5;
const int oo = 1e9;
vector <int> adj[Nmax],res[Nmax];
stack <int> st;
int n, m, cnt_num, cnt_strong_component;
int low[Nmax], num[Nmax];
void dfs(int u)
{
    num[u] = low[u] = ++cnt_num;
    st.push(u);
    for (int v: adj[u])
    {
        if (num[v])
            low[u] = min(low[u], num[v]);
        else
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        
    }
    if (low[u] == num[u])
    {
        cnt_strong_component++;
        int v=-1;
        while (u != v)
        {
            v = st.top();
            res[cnt_strong_component].push_back(v);
            st.pop();
            low[v] = num[v] = oo;
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
    }
    cnt_num = 0;
    for (int i = 1; i <= n; i++)
    {
        if (num[i] == 0)
        {
            dfs(i);
        }
    }
    int rem = 0, cnt_res=0;
    for (int i = 1; i <= cnt_strong_component; ++i)
    {
        if (res[i].size() > cnt_res)
        {
            cnt_res = res[i].size();
            rem = i;
        }
    }
    sort(res[rem].begin(), res[rem].end());
    cout << cnt_res << endl;
    for (int v: res[rem])
    {
        cout << v << " ";
    }
    return 0;
}