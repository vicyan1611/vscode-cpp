/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "ksan"
#define endl '\n'
using namespace std;
const int Nmax = 1e5 + 5;
struct cautruc
{
    int t, d;
    bool operator < (const cautruc &a)
    {
        if (t != a.t) return t < a.t;
        return d < a.d;
    }
};
cautruc a[Nmax];
int n;
stack <int> st;
priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair<int, int>>> pq;
int main()
{
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].t;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].d;
    }
    sort(1 + a, 1 + a + n);
    int pre = n;
    while (pre > 0)
    {
        st.push(pre);
        pre--;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        while (!pq.empty() && pq.top().first <= a[i].t)
        {
            st.push(pq.top().second);
            pq.pop();
        }
        pq.push({a[i].t + a[i].d, st.top()});
        res = max(res, st.top());
        st.pop();
    }
    cout << res;
    return 0;
}