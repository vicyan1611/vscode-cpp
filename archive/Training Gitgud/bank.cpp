/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "bank"
#define endl '\n'
using namespace std;
const int Nmax = 1e4 + 5;
struct cautruc
{
    int val, ti;
};
int n;
cautruc a[Nmax];
bool cmp(cautruc x, cautruc y)
{
    if (x.ti != y.ti) return x.ti < y.ti;
    return x.val < y.val;
}
long long f[10005][1003];
long long trau(int i, int time)
{
    if (i > n) return 0;
    long long &res = f[i][time];
    if (res != - 1) return res;
    if (time <= a[i].ti)
    {
        res = max(res, trau(i + 1, time + 1) + a[i].val);
        res = max(res, trau(i + 1, time));
    } else
    {
        res = max(res, trau(i + 1, time));
    }
    return res; 
}
int main()
{
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].val >> a[i].ti;
    }
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= 1001; ++j)
            f[i][j] = -1;
    }
    sort(1 + a, 1 + a + n, cmp);
    cout << trau(1,0);
    return 0;
}