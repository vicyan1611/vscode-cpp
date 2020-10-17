/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "sum1g"
#define endl '\n'
using namespace std;
const int Nmax = 4e5 + 5;
int a[Nmax];
int n, minl[Nmax], minr[Nmax], maxl[Nmax], maxr[Nmax];
stack <int> st1, ori, st2;
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        while (!st1.empty() && a[st1.top()] <= a[i]) st1.pop();
        while (!st2.empty() && a[st2.top()] >= a[i]) st2.pop();
        if (st1.empty()) maxl[i] = 1; else maxl[i] = st1.top() + 1;
        if (st2.empty()) minl[i] = 1; else minl[i] = st2.top() + 1;
        st1.push(i); st2.push(i);
    }
    st1 = st2 = ori;
    for (int i = n; i >= 1; --i)
    {
        while (!st1.empty() && a[st1.top()] < a[i]) st1.pop();
        while (!st2.empty() && a[st2.top()] > a[i]) st2.pop();
        if (st1.empty()) maxr[i] = n; else maxr[i] = st1.top() - 1;
        if (st2.empty()) minr[i] = n; else minr[i] = st2.top() - 1;
        st1.push(i); st2.push(i);
    }
    long long res = 0;
    for (int i = 1; i <= n; ++i)
    {
        res += (long long) ((maxr[i] - i + 1) * (i - maxl[i] + 1) - 1) * a[i];
        res -= (long long) ((minr[i] - i + 1) * (i - minl[i] + 1) - 1) * a[i];
    }
    cout << res;
    return 0;
}