#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string st;
int z[1000005];
vector <int> res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> st;
    int n = st.size();
    int x = 0, l = -1, r = -1;
    for (int i = 1; i < n; ++i)
    {
        if (i > r) x = 0; else x = min (z[i-l], r-i);
        while (st[x] == st[x+i] && x + i < n) x++;
        z[i] = x;
        if (i+x >= r)
        {
            l = i;
            r = i + x;
        }
    }
    for (int i = 0; i < n; ++i) if (i + z[i] == n) res.push_back(i);
    sort(res.begin(), res.end());
    res.push_back(n);
    for (int v :res) cout << v << " ";
    return 0;
}