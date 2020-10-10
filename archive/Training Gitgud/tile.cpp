#include <iostream>
#include <fstream>
using namespace std;
struct Tmatrix
{
    long long row,col;
    long long b[2][2];
};
const long long md = 1e9 + 7;
const long long Nmax = 1e6 + 5;
Tmatrix multi(Tmatrix A, Tmatrix B)
{
    Tmatrix C;
    C.row = A.row;
    C.col = B.col;
    for (long long i = 0; i < C.row; ++i)
    {
        for (long long j = 0; j < C.col; ++j)
        {
            C.b[i][j] = 0;
            for (long long k = 0; k < A.col; ++k)
            {
                C.b[i][j] += A.b[i][k] * B.b[k][j];
                C.b[i][j] %= md; 
            }
        }
    }
    return C;
}
Tmatrix chiadetri(Tmatrix A, long long n)
{
    if (n == 1) return A;
    Tmatrix tmp = chiadetri(A, n/2);
    if (n&1) return multi(multi(tmp, tmp), A);
    return multi(tmp, tmp);
}
int main()
{
   // freopen("tile.inp","r",stdin);
   // freopen("tile.out","w",stdout);
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if (n == 1) cout << 1 << endl;
        if (n == 2) cout << 3 << endl;
        if (n > 2)
        {
            Tmatrix basic;
            basic.col = 2;
            basic.row = 2;
            basic.b[0][0] = 0; basic.b[0][1] = 1; basic.b[1][0] = 2; basic.b[1][1] = 1;
            Tmatrix tile;
            tile.row = 2;
            tile.col = 1;
            tile.b[0][0] = 1;
            tile = multi(tile, chiadetri(basic, n+1));
            cout << tile.b[0][1] << endl;
        }
        
    }
    return 0;
}