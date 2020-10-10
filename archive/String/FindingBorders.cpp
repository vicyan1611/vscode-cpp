#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string st;
vector <int> res;
int z[1000006];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> st;
    int n = st.size();
    int x = 0, l = -1, r = -1;
    for (int i = 1; i < n; ++i)
    {
        if (i > r) x = 0; else x = min(z[i - l], r - i);
        while (st[x] == st[x+i] && i + x < n) x++;
        z[i] = x;
        if (x + i >= r)
        {
            l = i;
            r = x + i;
        }
    }
    for (int i = 1; i < n; ++i)
    {
        if (i + z[i] == n) res.push_back(z[i]);
    }
    sort(res.begin(), res.end());
    for (int v: res)
        cout << v << " ";
    return 0;
}