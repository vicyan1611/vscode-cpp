/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "rooms"
#define endl '\n'
using namespace std;
const long long Nmax = 1e6 + 5;
long long n;
stack <long long> st;
struct cautruc
{
    long long t, typ, num;
};
cautruc a[Nmax];
vector <long long> res[Nmax];
long long rem[Nmax];
bool cmp(cautruc x, cautruc y)
{
    if (x.t != y.t) return x.t < y.t; else
    {
        if (x.typ != y.typ) return x.typ < y.typ; else
        {
            return x.num < y.num;
        }
    }
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i].t >> a[i + n].t;
        a[i].t ++;
        a[i].typ = 1;
        a[i+n].typ = 2;
        a[i].num = a[i+n].num = i;
        st.push(n - i + 1);
    }
    n *= 2;
    sort(1 + a, 1 + a + n, cmp);
    long long cnt = 0;
    for (long long i = 1; i <= n; ++i)
    {
        if (a[i].typ == 1)
        {
            cnt = max(cnt, st.top());
            res[st.top()].push_back(a[i].num);
            rem[a[i].num] = st.top();
            st.pop();
        } else if (a[i].typ == 2)
        {
            st.push(rem[a[i].num]);
        }
    }
    cout << cnt << endl;
    for (long long i = 1; i <= cnt; ++i)
    {
        for (auto v: res[i])
            cout << v << " ";
        cout << endl;
    }
    return 0;
}