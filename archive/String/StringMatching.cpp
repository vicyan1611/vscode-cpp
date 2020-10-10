#include <iostream>
#include <string>
using namespace std;
string st1, st2;
int z[2000005];
int main()
{
    cin >> st1 >> st2;
    int x = 0 , l = -1, r = -1;
    st1 = st2 + st1;
    int n = st1.size();
    for (int i = 1; i < n; ++i)
    {
        if (i > r) x = 0; else x = min(z[i-l], r-i);
        while (st1[x] == st1[x+i] && x + i < n) x++;
        z[i] = x;
        if (i + x >= r)
        {
            l = i;
            r = i + x;
        }
    }
    int res = 0;
    for (int i = st2.size(); i < n; ++i)
    {
        if (z[i] >= st2.size()) res++;
    }
    cout << res << endl;
    return 0;
}