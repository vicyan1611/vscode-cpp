#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
const long long Nmax = 1e5 + 5;
long long n, m, k;
vector <long long> adj[Nmax], adjRev[Nmax], mi, ki;
long long disOne[Nmax], dism[Nmax], disk[Nmax];
 
void bfs(const vector <long long> startNode, vector <long long> adj[], long long dist[])
{
    for (long long i = 1; i <= n; ++i) dist[i] = 1e9;
    queue <long long> q;
    for (long long v: startNode)
    {
        q.push(v);
        dist[v] = 0;
    }
    while (!q.empty())
    {
        long long u = q.front();
        q.pop();
        for (long long v: adj[u])
        {
            if (dist[v] >= 1e9)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
int main()
{
    freopen("graph.inp","r",stdin);
    freopen("graph.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (long long i = 1; i <= m; ++i)
    {
        long long x;
        cin >> x;
        mi.push_back(x);
    }
    for (long long i = 1; i <= k; ++i)
    {
        long long x;
        cin >> x;
        ki.push_back(x);
    }
    for (long long i = 1; i <= n; ++i)
    {
        long long num;
        cin >> num;
        for (long long j = 1; j <= num; ++j)
        {
            long long x;
            cin >> x;
            adj[i].push_back(x);
            adjRev[x].push_back(i);
        }
    }
    bfs({1}, adj, disOne);
    bfs(mi, adjRev, dism);
    bfs(ki, adjRev, disk);
    long long res = 1e9;
    for (long long i = 1; i <= n; ++i)
    {
        res = min(res, disOne[i] + dism[i] + disk[i]);
    }
    if (res < 1e9) cout << res; else cout << "impossible";
    return 0;
}