/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "easy"
#define endl '\n'
using namespace std;
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long k;
    cin >> k;
    string st;
    while (cin >> st)
    {
        if (st.size() > k)
        {
            cout << st[0] << st.size() - 2 << st[st.size()-1] << " ";
        } else cout << st << " ";
    }
    
    return 0;
}