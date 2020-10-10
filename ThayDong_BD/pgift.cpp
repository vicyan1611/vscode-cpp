/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "pgift"
#define endl '\n'
using namespace std;
long long n = 4;
vector <pair <long long, long long>> tried, gener;
long long l[5], w[5];
long long x[5], res = 1e18;
long long xhv[5];
bool used[5];
struct hcn
{
    long long Ax, Ay, Dx, Dy;
};
bool checkk(hcn a, hcn b)
{
    bool tmp1 = min(a.Dx, b.Dx) <= max(a.Ax, b.Ax);
    bool tmp2 = min(a.Dy, b.Dy) <= max(a.Ay, b.Ay);
    return tmp1 || tmp2;
}
vector <hcn> old_hcn, gene;
void save()
{
    long long sums_low = 0;
    long long sums_right = 0;
    for (hcn v: old_hcn)
    {
        sums_low = max(sums_low, v.Dx);
        sums_right = max(sums_right, v.Dy);
    }
    res = min(res, sums_low * sums_right);
}
void solve(long long i)
{
    long long ll, ww;
    long long ii = xhv[i];
    if (x[ii] == 1) ll = w[ii], ww = l[ii]; else ll = l[ii], ww = w[ii];
    for (auto v: tried)
    {
        long long Ax = v.first;
        long long Ay = v.second;
        long long Dx = v.first + ll;
        long long Dy = v.second + ww;
        hcn tmp = {Ax, Ay, Dx, Dy};
        bool ok = true;
        for (hcn x: old_hcn)
        {
            if (!checkk(x, tmp)) ok = false;
        }
        if (ok == true)
        {
            old_hcn.push_back(tmp);
            tried.push_back({tmp.Ax, tmp.Ay});
            tried.push_back({tmp.Ax, tmp.Dy});
            tried.push_back({tmp.Dx, tmp.Ay});
            tried.push_back({tmp.Dx, tmp.Dy});
            if (i == n)
            {
                save();
            }  else solve(i + 1);
            old_hcn.pop_back();
            tried.pop_back(); tried.pop_back(); tried.pop_back(); tried.pop_back();
        }
    }
}
void calc()
{
    tried = gener;
    old_hcn = gene;
    solve(1);
}
void snp(long long i)
{
    for (long long j = 0; j <= 1; ++j)
    {
        x[i] = j;
        if (i == n) calc(); else snp(i + 1);
    }
}
void shv(long long i)
{
    for (long long j = 1; j <= n; ++j)
    {
        if (!used[j])
        {
            xhv[i] = j;
            used[j] = true;
            if (i == n) snp(1); else shv(i + 1);
            used[j] = false;
        }
    }
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (long long i = 1; i <= n; ++i)
    {
        cin >> l[i] >> w[i];
    }
    gener.push_back({0, 0});
    shv(1);
    cout << res;
    return 0;
}