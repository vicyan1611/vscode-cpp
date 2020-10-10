/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "trans"
#define endl '\n'
using namespace std;
set <int> uoc_a, uoc_b;
int a, b, d;
void timuoc()
{
    for (int i = 1; i * i <= a; ++i)
    {
        if (a % i == 0) 
        {
            uoc_a.insert(i);
            uoc_a.insert(a / i);
        }
    }
    for (int i = 1; i * i <= b; ++i)
    {
        if (b % i == 0)
        {
            uoc_b.insert(i);
            uoc_b.insert(b / i);
        }
    }
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> b >> d;
    int gcdd = __gcd(a, b);
    a /= gcdd;
    b /= gcdd;
    
    return 0;
}