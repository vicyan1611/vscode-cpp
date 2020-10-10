/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "A"
#define endl '\n'
using namespace std;
const int Nmax = 1e5 + 5;
int a[Nmax], remember[Nmax];
struct segmenttree
{
    int size;
    vector <int> sums;
    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        
    }
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    return 0;
}