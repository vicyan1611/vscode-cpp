/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "sqsort"
#define endl '\n'
using namespace std;
const int Nmax = 1 << 20;
int a[Nmax];
pair <int, int> pa[Nmax];
int p[Nmax], n, k;
vector <int> ans;
void tryy(vector <int> h, int layer, int l, int r, int x)
{
    if (layer > n) return;
    
    int mid = (l + r) / 2;
    vector <int> b, c;
    for (int v: h)
    {
        if (v <= mid)
        {
            b.push_back(v);
            ans.push_back(x);
            ans.push_back(x + 1);
        } else
        {
            c.push_back(v);
            ans.push_back(x);
        }
    }
    tryy(b, layer + 1, l, mid, x + 2);
    reverse(c.begin(), c.end());
    for (auto v : c)
        ans.push_back(v + 1);
    tryy(c, layer + 1, mid + 1, r, x + 2);
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < k; ++i)
    {
        pa[i] = make_pair(a[i], i);
    }
    sort(pa, pa + k);
    for (int i = 0; i < k; ++i)
    {
        p[i] = lower_bound(pa, pa + k, make_pair(a[i], i)) - pa + 1;
    }
    tryy(vector <int> (p, p + k), 1, 1, k, 1);
    cout << ans.size() << endl;
    for (int v: ans)
        cout << v << " ";
    return 0;
}