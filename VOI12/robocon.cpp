/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "robocon"
#define endl '\n'
using namespace std;
const int Nmax = 505;
const int Mmax = 255530;
int a1[Mmax], a2[Mmax];
int step = 0;
int n, k;
int pack(int u, int v){ return u * Nmax + v;}
vector <int> loang(int x, int tye)
{
    vector <int> res;
    if (tye == 1)
    {
        res.push_back(x + 1);
        res.push_back(x + Nmax);
        res.push_back(x + Nmax + 1);
    } else if (tye == 2)
    {
        res.push_back(x - 1);
        res.push_back(x + Nmax);
        res.push_back(x + Nmax - 1);
    }
    return res;
}
bool unpack(int s)
{
    int x = s / Nmax;
    int y = s % Nmax;
    return 1 <= x && x <= n && y <= n && 1 <= y;
}
vector <int> bfs(vector <int> q, int state[], int tye)
{
    vector <int> res;
    for (int v: q)
    {
        vector <int> tmp = loang(v, tye);
        for (int x: tmp)
        {
            if (state[x] >= 0 && state[x] != step && unpack(x) == true)
            {
                state[x] = step;
                res.push_back(x);
            }
        }
    }
    return res;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= k; ++i)
    {
        int x, y;
        cin >> x >> y;
        a1[pack(x, y)] = a2[pack(x, y)] = -1;
    }
    vector <int> robot1, robot2;
    robot1.push_back(pack(1, 1));
    robot2.push_back(pack(1, n));
    while (true)
    {
        ++step;
        robot1 = bfs(robot1, a1, 1);
        robot2 = bfs(robot2, a2, 2);
        for (int v: robot1)
        {
            if (a1[v] == a2[v]) return cout << step, 0;
        }
    }
    return 0;
}