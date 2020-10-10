/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "abba"
#define endl '\n'
using namespace std;
const int Nmax = 1e3 + 5;
string st;
int f[Nmax][Nmax];
int n, m;
string s1, s2;
bool checkk(int u, int v)
{
    string ss;
    if (u < v)
    {
        ss = " ";
        for (int i = u; i <= v; ++i)
            ss += s2[i];
    } else
    {
        ss = "";
        for (int i = v; i <= u; ++i)
            ss = s2[i] + ss;
        ss = " " + ss;
    }
    
    return ss == s1;
}
int trau(int u, int v)
{
    if (u < 1 || v < 1 || u > m || v > m || (abs(u - v) + 1 < n)) return f[u][v] = false;
    if (f[u][v] != -1) return f[u][v];
    if (max(u, v) - min(u, v) + 1 == n)
    {
        return f[u][v] = checkk(u, v);
    }
    int &res = f[u][v] = 0;
    if (u < v)
    {
        if (s2[u] == 'B')
        {
            res = res || trau(v, u + 1);
        }
        if (s2[v] == 'A')
        {
            res = res || trau(u, v - 1);
        }
    } else
    {
        if (s2[u] == 'B')
        {
            res = res || trau(v, u - 1);
        } 
        if (s2[v] == 'A')
        {
            res = res || trau(u, v + 1);
        }
    }
    return res;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while (cin >> st)
    {
        string tmp;
        cin >> tmp;
        st = st + " " + tmp;
        bool checks = false;
        s1 = "", s2 = "";
        for (int c: st)
        {
            if (c != ' ')
            {
                if (checks == false) s1.push_back(c); else s2.push_back(c);
            } else checks = true;
        }
        n = s1.size();
        m = s2.size();
        for (int i = 0; i <= m; ++i)
            for (int j = 0; j <= m; ++j)
                f[i][j] = -1;
        s1 = " " + s1;
        s2 = " " + s2;
        if (trau(1, m)) cout << "Yes" << endl; else cout << "No" << endl;
    }
    return 0;
}