#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
const long long Nmax = 200005;
long long n;
bool vis[Nmax];
long long a[Nmax], p[Nmax], cost[Nmax];
vector <pair <long long, long long>> adj[Nmax];
queue <long long> q;
void bfs(long long s)
{
    q.push(s);
    vis[s] = true;
    cost[s] = a[s];
    while (!q.empty())
    {
        long long u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); ++i)
        {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (vis[v] == false)
            {
                vis[v] = true;
                cost[v] = cost[u] + w;
                q.push(v);
            }
        }
    }
}
int main()
{
    freopen("summax1.inp","r",stdin);
    freopen("summax1.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (long long i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (long long i = 1; i <= n; ++i)
    {
        cin >> p[i];
        if (i != 1)
        {
            adj[i].push_back({p[i], a[i]});;
            adj[p[i]].push_back({i, a[i]});
        } 
    }
    bfs(1);
    long long res = 0;
    for (long long i = 1; i <= n; ++i)
    {
        res = max(res, cost[i]);
    }
    cout << res << endl;
    return 0;
}