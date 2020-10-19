/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "hfamous"
#define endl '\n'
using namespace std;
const int Nmax = 1e5 + 5;
vector <int> adj[Nmax];
int n, m, k;
stack <int> st;
int size[Nmax];
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >>k;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        size[x]++;
        size[y]++;
        adj[y].push_back(x);
    }
    for (int i = 1; i <= nn)
    return 0;
}