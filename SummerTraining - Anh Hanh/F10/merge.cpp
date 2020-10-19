/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "merge"
#define endl '\n'
using namespace std;
string stt[105];
long long n;
long long soto(string xau)
{
    long long so;
    stringstream ss;
    ss << xau;
    ss >> so;
    return so;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    string st;
    getline(cin, st);
    while (n--)
    {
        getline(cin, st);
        st = " " + st;
        long long cnt = 0;
        for (long long i = 0; i < st.size(); ++i)
        {
            if (st[i] == ' ') cnt ++, stt[cnt] = ""; else
            {
                stt[cnt] += st[i];
            }
        }
        long long num = soto(stt[cnt]);
        cout << stt[num] << " ";    
    }
    return 0;
}