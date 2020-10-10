/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "sqsum"
#define endl '\n'
using namespace std;
int s;
bool checkk(int x)
{
    if (x == s)
        return true;
    if (x % 10 == 0) return false;
    bool pre10 = false;
    for(int numdig = 1; numdig <= 10; ++numdig)
    {
        if (pre10 == true && (x + numdig - 1) % 10 == 1) return false;
        if ((x + (numdig - 1)) % 10 == 0) pre10 = true;
        int y = x + numdig - 1;
        int sums = ((y + x) * numdig) / 2;
        int pre = sums;
        for (int i = 1; i < numdig; ++i)
        {
            
            pre += 10 * numdig;
            sums += pre;
        } 
        if (sums == s) return true;
    }
    return false;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    int res = 1e9;
    for (int i = 1; i <= s; ++i)
    {
        if (checkk(i) == true) res = min (res, i);
    }
    cout << res;
    return 0;
}