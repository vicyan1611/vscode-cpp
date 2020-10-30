/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "F"
#define endl '\n'
using namespace std;
const long long Nmax = 1e6 + 5;
long long z[Nmax];
string st1, st2;
const long long md = 1e9 + 7;
const long long base = 27;
long long res, Pow[Nmax], h[Nmax], n, m;
string st;
long long get_Hash(long long i, long long j)
{
    return (h[j] - h[i-1] * Pow[j-i+1] + md * md) %md;
}
long long bnrs(long long s, long long t)
{
    long long l = 1, r = n, k = 0;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        if (get_Hash(s, s + mid - 1) == get_Hash(t, t + mid - 1))
        {
            k = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return k;
}
void solve(long long s)
{
    long long x = bnrs(res, s);
    if (st[res + x] > st[s + x]) res = s;
}
void lexio()
{
    n = st.size();
    st = st + st;
    m = st.size();
    st = " " + st;
    Pow[0] = 1;
    res = 1;
    for(long long i = 1; i <= m; ++i)
    {
        h[i] = (h[i-1]*base + st[i]) % md;
        Pow[i] = (Pow[i-1] * base) % md;
    }
    for (long long i = 2; i <= n; ++i)
    {
        solve(i);
    }
    for (long long i = res; i < n + res; ++i)
    {
        cout << st[i];
    }
}

int main()
{
   // freopen(task".inp","r",stdin);
  //  freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long ab;
    cin >> ab;
    string tmp;
    getline(cin, tmp);
    getline(cin, st1);
    getline(cin, st2);
    string of_st1 = "", of_st2 = "";
    string st_now = "";
    for (long long i = 0 ; i < st1.size(); ++i)
    {
        if ((st1[i] >= 'a' && st1[i] <= 'z') || (st1[i] >= 'A' && st1[i] <= 'Z'))
        {
            long long tmp1 = tolower(st1[i]) - 96;
            long long tmp2 = tolower(st2[i]) - 96;
            long long intchar = 0;
            if (tmp2 <= tmp1)
            {
                intchar = tmp2 - tmp1 + 26;
                st_now.push_back(intchar + 96);
            } else
            {
                intchar = tmp2 - tmp1;
                st_now.push_back(intchar + 96);
            }
            
        }
    }
    z[0] = st_now.size();
    long long l = -1, r = -1, x = 0;
    for (long long i = 1; i < st_now.size(); ++i)
    {
        if (i > r) x = 0; else x = min(z[i-l], r - i);
        while (st_now[x] == st_now[i+x] && i + x < st_now.size()) x++;
        z[i] = x;
        if (i + x >= r)
        {
            l = i;
            r = i + x;
        }   
    }
    string res = "";
    res += st_now[0];
    for (long long i = 1; i <= st_now.size(); ++i)
    {
        if (st_now.size() - z[i] == i)
        {
            st = res;
            lexio();
            return 0;
        }
        res += st_now[i];
    }
    return 0;
}