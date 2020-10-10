/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "cperm"
#define endl '\n'
using namespace std;
const long long md = 1e9 + 7;
long long t, n, res;
bool used1, used0, first;
long long chiadetri(long long a, long long n)
{
    if (n == 0)
    {
        if (used0 == false)
        {
            res += 1;
            used0 = true;
        }
        return 1;
    } 
    if (n == 1)
    {
        if (used1 == false)
        {
            res += a;
            used1 = true;
        } 
        return a;
    } 
    long long tmp = chiadetri(a, n / 2);
    if (n&1)
    {
        long long re = (a * tmp * tmp) % md;
        res += re;
        res %= md;
        tmp = chiadetri(a, (n + 1) / 2);
        return re;
    } else
    {
        long long re = (tmp * tmp) % md;
        res += re;
        res %= md;
        tmp = chiadetri(a, (n + 1) / 2);
        return re;
    }
    
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n <= 2)
        {
            cout << 0 << endl;
            continue;
        }
        res = 0;
        used1 = false;
        used0 = false;
        first = 0;
        long long tmp = chiadetri(2, n - 2);
        cout << res << endl;
    }
    return 0;
}