#include <iostream>
#include <fstream>
using namespace std;
const long long md = 1e9 + 7;
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
    freopen("fibos.inp","r",stdin);
    freopen("fibos.out","w",stdout);
    long long n;
    cin >> n;
    Tmatrix basic;
    basic.col = 3;
    basic.row = 3;
    basic.b[0][0] = 0; basic.b[0][1] = 1; basic.b[0][2] = 0;
    basic.b[1][0] = 1; basic.b[1][1] = 1; basic.b[1][2] = 0;
    basic.b[2][0] = 1; basic.b[2][1] = 1; basic.b[2][2] = 1;
    Tmatrix fibo;
    fibo.row = 3;
    fibo.col = 1;
    fibo.b[0][0] = 1; fibo.b[1][0] = 1; fibo.b[2][0] = 2;
    if (n == 0) return cout << 1, 0;
    if (n == 1) return cout << 2, 0;
    fibo = multi(chiadetri(basic, n - 1), fibo);
    cout << fibo.b[2][0];
    return 0;
}