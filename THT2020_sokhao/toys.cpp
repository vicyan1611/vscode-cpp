/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "toys"
#define endl '\n'
using namespace std;
const int Nmax = 200005;
long long a[Nmax], b[Nmax], fa[Nmax], fb[Nmax];
vector<int> pos[Nmax];
vector<int> pos2[Nmax];
int cnt[Nmax];
int n, m;
pair <int, int> fav[Nmax];
int main()
{
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> fav[i].first >> fav[i].second;
        pos[fav[i].first].push_back(i);
        pos2[fav[i].second].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = fa[i-1] + a[i];
        fb[i] = fb[i-1] + b[i];
    }
    long long res = fa[n] + fb[n];
    for(int i = 1; i <= n; ++i)
        for(int j = i - 1; j <= n; ++j)
            for(int l = 1; l <= n; ++l)
                for(int r = l - 1; r <= n; ++r){
                    long long tong = fa[j] - fa[i - 1] + fb[r] - fb[l - 1];
                    for(int k = i; k <= j; ++k){
                        for(int v : pos[k])
                            ++cnt[v];
                    }            
                    for(int k = l; k <= r; ++k){
                        for(int v : pos2[k])
                            ++cnt[v];
                    }
                    int cur = 0;
                    for(int k = 1; k <= m; ++k){
                        if(cnt[k] > 0)
                            ++cur;
                        cnt[k] = 0;
                    }
                    if(cur == m)
                        res = min(res, tong);
                }
    cout << res;
    return 0;
}