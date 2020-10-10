#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int Nmax = 2e5 + 5;
string s, t;
int n, m;
bool ok[Nmax][27];
vector <int> res;
void solve(int a, int b)
{
    string str = "";
    for (char c: t)
    {
        if (c - 'a' == a) str += c; else
        if (c - 'a' == b) str += c; else
        str += '.';
    }
    str += '#';
    for (char c: s)
    {
        if (c - 'a' == a) str += b + 'a'; else
        if (c - 'a' == b) str += a + 'a'; else
        str += '.';
    }
    vector <int> z(m + n + 1, 0);
    int x = 0;
    int l = -1, r =1;
    for (int i = 1; i <= m + n; ++i)
    {
        if (i > r) x = 0; else x = min(z[i-l], r - i);
        while (str[x] == str[x+i] && i + x <= m + n) x++; 
        z[i] = x;
        if (x + i >= r)
        {
            l = i;
            r = x + i;
        }
        if (x == m) ok[i-m][a] = ok[i-m][b] = true;
    }
}
int main()
{
    cin >> n >> m >> s >> t;
    for (int i = 0; i < 26; ++i)
    {
        for (int j = i; j < 26; ++j)
        {
            solve(i, j);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        res.push_back(i);
        for (int j = 0; j < 26; ++j)
            if (!ok[i][j])
            {
                res.pop_back();
                break;
            }
    }
    cout << res.size() << endl;
    for (int v: res)
        cout << v << " ";
    return 0;
}