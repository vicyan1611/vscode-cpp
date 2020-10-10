#include <iostream>
#include <fstream>
using namespace std;
long long n, md;
struct Tmatrix
{
    long long row, col;
    long long b[3][3];
};
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
                C.b[i][j] += A.b[i][k]*B.b[k][j];
                C.b[i][j] %= md;
            }
        }
    }
    return C;
}
Tmatrix chiadetri(Tmatrix A, long long n)
{
    if (n == 1) return A;
    Tmatrix tmp = chiadetri(A,n/2);
    if (n&1) return multi(multi(tmp, tmp), A);
    return multi(tmp, tmp);
}
int main()
{
    freopen("loco.inp","r",stdin);
    freopen("loco.out","w",stdout);
    cin >> n >> md;
    Tmatrix basic;
    basic.row = 3;
    basic.col = 3;
    basic.b[0][0] = 0;
    basic.b[0][1] = 1;
    basic.b[0][2] = 0;
    basic.b[1][0] = 0;
    basic.b[1][1] = 0;
    basic.b[1][2] = 1;
    basic.b[2][0] = 1;
    basic.b[2][1] = 1;
    basic.b[2][2] = 1;
    Tmatrix loco;
    loco.row = 3;
    loco.col = 1;
    loco.b[0][0] = 1;
    loco.b[1][0] = 2;
    loco.b[2][0] = 4;
    if (n == 1) return cout << 1, 0;
    if (n == 2) return cout << 2, 0;
    if (n == 3) return cout << 4, 0;
    loco = multi(chiadetri(basic, n-3), loco);
    cout << loco.b[2][0];
    return 0;
}