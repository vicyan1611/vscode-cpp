#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
const int Nmax = 55;
const int md = 2017;
int adj[Nmax][Nmax];
struct Tmatrix
{
    int x, y, mat[Nmax][Nmax];
    void init(int n)
    {
        x = n;
        y = n;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
                mat[i][j] = adj[i][j];
        }
    }
    Tmatrix operator * (const Tmatrix &a)
    {
        Tmatrix c;
        c.x = a.x;
        c.y = y;
        for (int i = 1; i <= x; ++i)
        {
            for (int j = 1; j <= y; ++j)
            {
                c.mat[i][j] = 0;
                for (int k = 1; k <= x; ++k)
                {
                    c.mat[i][j] += mat[i][k] * a.mat[k][j];
                    c.mat[i][j] %= md;
                }
            }
        }
        return c;
    }
    int res(int n)
    {
        return mat[1][n];
    }
    void output()
    {
        for (int i = 1; i <= x; ++i)
        {
            for (int j = 1; j <= y; ++j)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }
};

Tmatrix chiadetri(Tmatrix a, int n)
{
    if (n == 1) return a;
    Tmatrix tmp = chiadetri(a, n / 2);
    if (n & 1) return tmp * tmp * a;
    return tmp * tmp;
}
int main()
{
    freopen("cpath.inp","r",stdin);
    freopen("cpath.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] ++;
    }
    Tmatrix matrix;
    matrix.init(n);
    matrix = chiadetri(matrix, k);
    cout << matrix.res(n) << endl;
    return 0;
}