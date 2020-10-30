/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "addedge"
#define endl '\n'
using namespace std;
const long long Nmax = 1e7 + 5;
long long m, s, t;
struct canhbt
{
    long long u, v;
};
canhbt ed[Nmax];
bool ok;
vector <long long> adj[Nmax];
bool vis[Nmax];
void dfs(long long vd, long long u)
{
    vis[u] = true;
    if (u == vd)
    {
        ok = true;
        vis[u] = true;
    }
    if (ok == true) return;
    for (auto v: adj[u])
    {
        if (vis[v] == false)
        {
            dfs(vd ,v);
        }
    }
}
bool checkk(long long num_edge)
{
    set <long long> node;
    map <long long, long long> m1, m2;
    set <pair <long long, long long>> edge;
    for (long long i = 1; i <= num_edge; ++i)
    {
        node.insert(ed[i].u);
        node.insert(ed[i].v);
        adj[i].clear();
        vis[i] = false;
    }
    vis[num_edge + 1] = false;
    adj[num_edge + 1].clear();
    long long cnt = 0;
    for (auto it = node.begin(); it != node.end(); ++it)
    {
        cnt++;
        m1[*it] = cnt;
        m2[cnt] = *it;
    }
    if (m1[s] == 0 || m1[t] == 0) return false;
    for (long long i = 1; i <= num_edge; ++i)
    {
        edge.insert(make_pair(m1[ed[i].u], m1[ed[i].v]));
    }
    for (auto x: edge)
    {
        adj[x.first].push_back(x.second);
    }
    ok = false;
    dfs(m1[t], m1[s]);
    return vis[m1[t]];
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> s >> t;
    for (long long i = 1; i <= m; ++i)
    {
        cin >> ed[i].u >> ed[i].v;
    }
    long long l = 1, r = m;
    long long res = 0;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        if (checkk(mid) == true)
        {
            r = mid - 1;
            res = mid;
        }  else l = mid + 1;
    }
    cout << res;
    return 0;
}