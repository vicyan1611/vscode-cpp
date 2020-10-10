#include <iostream>
#include <string>
using namespace std;
const long long Nmax = 1e6 + 5;
const long long md = 1e9 + 7;
long long n, cnt, f[Nmax];
long long adj[27][Nmax];
bool isEnd[Nmax];
string sta;
long long trau(long long i)
{
    if (i > n) return 1;
    long long &res = f[i];
    if (res != -1) return res;
    res = 0;
    long long j = i, node = 0, x;
    while (true)
    {
        x = sta[j] - 97;
        if (adj[x][node] == 0) break;
        node = adj[x][node];
        j++;
        if (isEnd[node] == true) res= (res + trau(j)) % md;
        //if (j > n) return res;
    }
    return res;
}
void add (string st)
{
    long long x = 0, node = 0;
    for (char c: st)
    {
        x = c- 'a';
        if (adj[x][node] == 0)
            adj[x][node] = ++cnt;
        node = adj[x][node];
    }
    isEnd[node] = true;
}
int main()
{
   // freopen("depart.inp","r",stdin);
   // freopen("depart.out","w",stdout);
    cin >> n;
    for (long long i = 1; i <= n; ++i)
    {
        string st;
        cin >> st;
        add(st);
    }
    cin >> sta;
    long long n = sta.size();
    for (int i = 0; i <= n; ++i)
        f[i] = -1;
    cout << trau(0);
    return 0;
}