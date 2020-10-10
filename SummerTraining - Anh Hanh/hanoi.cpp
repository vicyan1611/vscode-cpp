/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "hanoi"
#define endl '\n'
using namespace std;
int r, c, k;
const int Nmax = 1005;
int pre_x[4] = {0 ,0 , -1, 1};
int pre_y[4] = {1 ,-1 , 0, 0};
char a[Nmax][Nmax];
int typ[Nmax][Nmax], cnt[Nmax][Nmax];
bool used[Nmax][Nmax];
bool vis[Nmax][Nmax];
vector <pair <int, int>> lake;

bool loang(int x, int y)
{
    if (typ[x][y] != -1) return typ[x][y];
    if (a[x][y] == '#') return true;
    if (x == 1 || x == r || y == 1 || y == c) return false;
    typ[x][y] = 1;
    for (int i = 0; i < 4; ++i)
    {
        typ[x][y] = typ[x][y] && loang(x + pre_x[i], y + pre_y[i]);
    }
    return typ[x][y];
}

int dem(int x, int y)
{
    if (cnt[x][y] != -1) return cnt[x][y];
    if (a[x][y] == '#') return 0;
    cnt[x][y] = 0;
    for (int i = 0; i < 4; ++i)
    {
        if (used[x + pre_x[i]][y + pre_y[i]] == false) cnt[x][y] += dem(x + pre_x[i], y + pre_y[i]);
        used[x + pre_x[i]][y + pre_y[i]] = true;
    }
    cnt[x][y] += 1;
    return cnt[x][y];
}
bool cmp(pair <int, int> a, pair <int, int> b)
{
    return cnt[a.first][a.second] < cnt[b.first][b.second];
}
void lamlai(int x, int y)
{
    if (typ[x][y] == 1 && vis[x][y] == false)
    {
        a[x][y] = '#';
        vis[x][y] = true;
        for (int i = 0; i < 4; ++i)
        {
            lamlai(x + pre_x[i], y + pre_y[i]);
        }
    } else return;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> r >> c >> k;
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            cin >> a[i][j];
            typ[i][j] = -1;
            cnt[i][j] = -1;
        }
    }
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            if (a[i][j] == '.' && typ[i][j] == -1)
            {
                if (loang(i, j))
                {
                    typ[i][j] = 1;
                    int tmp = dem(i, j);
                    lake.push_back({i, j});
                }  else typ[i][j] = 0;
            }
        }
    }
    sort(lake.begin(), lake.end(), cmp);
    int res = 0, needde = lake.size() - k;
    for (auto v: lake)
    {
        if (needde == 0) break;
        res += cnt[v.first][v.second];
        lamlai(v.first, v.second);
        needde--;
    }
    cout << res << endl;
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
            cout << a[i][j];
        cout << endl;
    }
    return 0;
}