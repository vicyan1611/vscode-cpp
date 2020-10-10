#include <iostream>
#define md 111539786
using namespace std;
//ifstream fi ("fibsum.inp");
//ofstream fo ("fibsum.out");
struct Tmatrix
{
    long long row,col;
    long long b[2][2];
};
Tmatrix multiply(Tmatrix A, Tmatrix B)
{
    Tmatrix C;
    C.row=A.row;
    C.col=B.col;
    for (long long i=0;i<C.row;++i)
    {
        for (long long j=0;j<C.col;++j)
        {
            C.b[i][j] = 0;
            for (long long k=0;k<A.col;++k)
            {
                C.b[i][j]=(C.b[i][j]+A.b[i][k]%md*B.b[k][j]%md)%md;
            }
        }
    }
    return C;
}
Tmatrix chiadetri(Tmatrix A, long long n)
{
    if (n==1)
    {
        return A;
    }
    if (n&1)
    {
        Tmatrix tmp=chiadetri(A,n/2);
        return multiply(multiply(tmp,tmp),A);
    } else
    {
        Tmatrix tmp=chiadetri(A,n/2);
        return multiply(tmp,tmp);
    }
}
int main()
{
    long long t;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        Tmatrix tmp;
        tmp.col=2;
        tmp.row=2;
        tmp.b[0][0]=0;tmp.b[0][1]=1;tmp.b[1][0]=1;tmp.b[1][1]=1;
        Tmatrix fib;
        fib.col=2;
        fib.row=1;
        fib.b[0][0]=0;
        fib.b[0][1]=1;
        if (n==1)
        {
            cout<<1<<endl;
        } else
        {
            fib=multiply(fib,chiadetri(tmp,n+1));
            cout<<fib.b[0][0]<<endl;
        } 
    }
    return 0;
}