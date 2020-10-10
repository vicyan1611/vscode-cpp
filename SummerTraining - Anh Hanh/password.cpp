#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string st;
int num, a[26];
int main()
{
    freopen("password.inp","r",stdin);
    freopen("password.out","w",stdout);
    cin >> st >> num;
    int res = 0;
    for (int i = 0; i < 26; ++i)
    {
        a[i] = (i + num) % 26;
    }
    for (char c: st)
    {
        res += a[c - 'a'];      
    }
    cout << res;
    return 0;
}