/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "str"
#define endl '\n'
using namespace std;
string st[4];
int x[4], used[4], vis[4];
string merge(string st1, string st2)
{
    string st = st1 + "#" + st2;
    int x = 0, l = r = -1;
    int n = st.size();
    z[0] = n;
    for (int i = 1; i < n; ++i)
    {
        if (i > r) x = 0; else x = min(z[i-l], r - i );
        while (st[x] == st[i+x] && i + x < n) x++;
        z[i] = x;
        if (i + x >= r)
        {
            l = i;
            r = i + x;
        }
    }
    for (int i = st1.size(); i <= n; ++i)
    {
        res = 
    } 
}
void solve()
{
    st1 = merge(st[x[1]], st[x[2]]);
}
void shv(int i)
{
    for (int j = 1; j <= n; ++j)
    {
        if (used[j] == false)
        {
            x[i] = j
            vis[j] = true;
            if (i == n) solve(); else shv(i + 1);
            vis[j] = false;
        }
    }
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> st[1] >> st[2] >> st[3];
    shv(1);
    return 0;
}