/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "aquarium"
#define endl '\n'
using namespace std;
const int Nmax = 1000005;
vector <int> t[Nmax];
vector <int> lef[Nmax], righ[Nmax], top[Nmax], bot[Nmax];
string diag[Nmax];
struct disjointSet
{
    vector <int> cha;
    disjointSet(int n = 0)
    {
        cha.assign(n + 7, -1);
    }
    int get_root(int x)
    {
        if (cha[x] < 0) return x; else return cha[x] = get_root(cha[x]);
    }
    bool uni(int u, int v)
    {
        u = get_root(u);
        v = get_root(v);
        if (u == v) return false;
        if (cha[u] > cha[v]) swap(u, v);
        int x = cha[u] + cha[v];
        cha[u] = x;
        cha[v] = u;
        return true;
    }
};
struct edge
{
    int u, v, w, i, j;
    bool operator < (const edge & a) const
    {
        return w < a.w;
    }
};
vector <edge> e;
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int r, c;
    cin >> r >> c;
    for (int i = 1; i <= r; ++i)
    {
        cin >> diag[i];
    }
    for (int i = 1; i <= r; ++i) 
    {
        t[i].assign(c + 1, 0);
        for (int j = 1; j <= c; ++j)
        {
            cin >> t[i][j];
        }
    }
    for (int i = 1; i <= r; ++i)
    {
        top[i].assign(c + 1, 0);
        bot[i].assign(c + 1, 0);
        righ[i].assign(c + 1, 0);
        lef[i].assign(c + 1, 0);
    }
    int numNode = 0;
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            lef[i][j] = ++numNode;
            top[i][j] = ++numNode;
            righ[i][j] = ++numNode;
            bot[i][j] = ++numNode;         
        }
    }
    disjointSet dsu(numNode);
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j  <= c; ++j)
        {
            if (i < r) dsu.uni(bot[i][j], top[i+1][j]);
            if (j < c) dsu.uni(righ[i][j], lef[i][j+1]);
            e.push_back({top[i][j], bot[i][j], t[i][j], i, j});
            if (diag[i][j-1] == '/')
            {
                dsu.uni(lef[i][j], top[i][j]);
                dsu.uni(bot[i][j], righ[i][j]);
            } else
            {
                dsu.uni(top[i][j], righ[i][j]);
                dsu.uni(bot[i][j], lef[i][j]);
            }
        }
    }
    sort(e.begin(), e.end());
    long long res = 0;
    for (edge E:e)
    {
        if (dsu.uni(E.u, E.v))
        {
            res += E.w;
            diag[E.i][E.j-1]='.';
        }   
    }
    cout << res << endl;
    for (int i = 1; i <= r; ++i)
    {
        cout << diag[i] << endl;
    }
    return 0;
}