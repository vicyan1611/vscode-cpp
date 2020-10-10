/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "SUMINT"
#define endl '\n'
using namespace std;
long long n;
vector <pair <long long, long long>> res;
void cal(long long soluong)
{
    if ((n * 2) % soluong == 0)
    {
        long long tong = (n * 2) / soluong;
        if ((tong - soluong + 1) % 2 != 0) return;
        long long sodau = (tong - soluong + 1) / 2;
        long long socuoi = sodau + soluong - 1;
        res.push_back({sodau, socuoi});
    }
}
int main()
{
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (long long i = 2; i * (i + 1) / 2 <= n; ++i)
    {
        cal(i);
    }
    cout << res.size() << endl;
    for (auto v: res)
    {
        cout << v.first << " " << v.second << endl;
    }
    return 0;
}