#include <iostream>
#include <string>
using namespace std;
const long long md = 1e9 + 7;
string st;
long long cnt[26], gt[1000006];
long long exp(long long a, long long n)
{
    if (n == 0) return 1;
    if (n == 1) return a;
    long long tmp = exp(a, n/2);
    if (n&1) return (((tmp * tmp) % md) * a) % md;
    return (tmp * tmp) % md;
}
int main()
{
    cin >> st;
    gt[0] = 1;
    gt[1] = 1;
    for (long long i = 2; i <= st.size(); ++i)
    {
        gt[i] = (gt[i-1] * i) % md;
    }
    for (char c: st)
    {
        cnt[c - 'a']++;
    }
    long long tich = 1;
    for (long long i = 0; i< 26; ++i)
    {
        tich *= gt[cnt[i]];
        tich %= md;
    }
    cout << (gt[st.size()] * exp(tich, (long long) 1e9 + 5)) % md;
    return 0;
}