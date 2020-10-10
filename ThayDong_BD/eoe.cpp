/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "eoe"
#define endl '\n'
using namespace std;
string st;
string loaix, loaiy;
stack <long long> stt;
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> st;
    cin >> loaix >> loaiy;
    for (long long i = 0; i < st.size(); ++i)
    {
        if (st[i] == 'x')
        {
            if (loaix == "Odd") st[i] = '1'; else st[i] = '2';
        }
        if (st[i] == 'y')
        {
            if (loaiy == "Odd") st[i] = '1'; else st[i] = '2';
        }
    }
    if (st[0] != '-' || st[0] != '+') st = '+' + st;
    long long i = 0, j = 0;
    while (i < st.size())
    {
        if (st[i] == '-')
        {
            j = i + 1;
            while (j < st.size() && st[j] != '+' && st[j] != '-' && st[j] != '*') j++;
            stt.push(-(st[j-1] - '0'));
            i = j - 1;
        } else if (st[i] == '+')
        {
            j = i + 1;
            while (j < st.size() && st[j] != '+' && st[j] != '-' && st[j] != '*') j++;
            stt.push(st[j-1] - '0');
            i = j -1;
        } else if (st[i] == '*')
        {
            j = i + 1;
            while (j < st.size() && st[j] != '+' && st[j] != '-' && st[j] != '*') j++;
            long long tmp = stt.top() * (st[j-1] - '0');
            stt.pop();
            stt.push(tmp);
            i = j - 1;
        }
        i++;
    }
    long long res = 0;
    while (!stt.empty())
    {
        res += stt.top();
        stt.pop();
    }
    if (abs(res) & 1) cout << "Odd"; else cout << "Even";
    return 0;
}