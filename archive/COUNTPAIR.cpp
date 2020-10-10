#include <iostream>
#include <string>
using namespace std;
const long long Nmax = 1e6 + 5;
string st;
long long count1, vt1[Nmax], cnt1[Nmax], cnt2[Nmax];
int main()
{
    cin >> st;
    long long n = st.size();
    st = " " + st;
    for (long long i = 1; i <= n; ++i)
    {
        if (st[i] == '1')
        {
            cnt1[i] = cnt1[i-1] + 1;
            vt1[++count1] = i;
        } else cnt1[i] = cnt1[i-1];
        if (st[i] == '2' ) cnt2[i] = cnt2[i-1] + 1; else cnt2[i] = cnt2[i-1];
    }
    long long res = 0;
    for (long long i = 1; i <= n; ++i)
    {
        if (st[i] == '2')
        {
            res += cnt1[i];
        }
    }
    cout << res;
    return 0;
}