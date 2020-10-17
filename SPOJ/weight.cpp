/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "weight"
#define endl '\n'
using namespace std;
const long long Nmax = 4e6 + 5;
long long a[Nmax];
long long n, minl[Nmax], minr[Nmax], maxl[Nmax], maxr[Nmax];
stack <long long> st1, ori, st2;
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (long long i = 1; i <= n; ++i)
        cin >> a[i];
    for (long long i = 1; i <= n; ++i)
    {
        while (!st1.empty() && a[st1.top()] <= a[i]) st1.pop();
        while (!st2.empty() && a[st2.top()] >= a[i]) st2.pop();
        if (st1.empty()) maxl[i] = 1; else maxl[i] = st1.top() + 1;
        if (st2.empty()) minl[i] = 1; else minl[i] = st2.top() + 1;
        st1.push(i); st2.push(i);
    }
    st1 = st2 = ori;
    for (long long i = n; i >= 1; --i)
    {
        while (!st1.empty() && a[st1.top()] < a[i]) st1.pop();
        while (!st2.empty() && a[st2.top()] > a[i]) st2.pop();
        if (st1.empty()) maxr[i] = n; else maxr[i] = st1.top() - 1;
        if (st2.empty()) minr[i] = n; else minr[i] = st2.top() - 1;
        st1.push(i); st2.push(i);
    }
    long long res = 0;
    for (long long i = 1; i <= n; ++i)
    {
        res += (long long) ((i - maxl[i]) + (i - maxl[i] + 1) * (maxr[i] - i) )* a[i];
        res -= (long long) ((i - minl[i]) + (i - minl[i] + 1) * (minr[i] - i) )* a[i];
    }
    cout << res;
    return 0;
}