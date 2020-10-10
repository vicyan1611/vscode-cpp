#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
const long long Nmax = 1e6 + 5;
const long long md = 1e9 + 7;
long long adj[Nmax][27];
bool isEnd[Nmax];
long long cnt, n, f[Nmax];
string sta;
bool len[1000001];
vector<int> dodai;
void add(string st)
{
    long long node = 0;
    long long x = 0;
    for (char c: st)
    {
        x = c - 'a';
        if (adj[node][x] == 0) adj[node][x] = ++cnt;
        node = adj[node][x];
    }
    isEnd[node] = true;
}
bool chec(string st)
{
    long long node = 0;
    long long x = 0;
    for (char c: st)
    {
        x = c - 'a';
        node = adj[node][x];
        if (node == 0) return false;
    }
    return isEnd[node];
}
long long trau(long long i)
{
    if (i == n) return 1;
    long long &res = f[i];
    if (res != -1) return res;
    string tmp = "";
    res = 0;
    for (long long j = i + 1; j <= min(n - i, 2000); ++j)
    {
        tmp = tmp + sta[j];
        if (chec(tmp)) res += trau(j);
        res %= md;
    }
    return res;
}
int main()
{
    //freopen("WordCombinations.inp","r",stdin);
    //freopen("WordCombinations.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> sta;
    cnt = 0;
    cin >> n;
    for (long long i = 1; i <= n; ++i) 
    {
        string x;
        cin >> x;
        add(x);
        len[x.size()] = true;
    }
    for(int i = 1;i<=5000; ++i)
        if (len[i] && i<=n) dodai.push_back(i);
    n = sta.size();
    for (long long i = 0; i <= n; ++i)
    {
        f[i] = -1;
    }
    sta = " " + sta;
    cout << trau(0);
    return 0;
}
