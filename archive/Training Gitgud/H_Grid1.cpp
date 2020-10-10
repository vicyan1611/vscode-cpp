#include <iostream>
#define md 1000000007
using namespace std;
long long n,m,f[1003][1003];
char a[1003][1003];
long long trau(long long i,long long j)
{
    if (i>n||j>m)
    {
        return 0;
    }
    if (i==n&&j==m)
    {
        return 1;
    }
    if (a[i][j]=='#') return 0;
    long long &res=f[i][j];
    if (res!=-1) return res;
    res=0;
    res=(res+trau(i+1,j)%md)%md;
    res=(res+trau(i,j+1)%md)%md;
    return res;
}
int main()
{
    //freopen("H_Grid1.inp","r",stdin);
    //freopen("H_Grid1.out","w",stdout);
    cin>>n>>m;
    for (long long i=1;i<=n;++i)
        for (long long j=1;j<=m;++j)
            f[i][j]=-1;
    for (long long i=1;i<=n;++i)
    {
        for (long long j=1;j<=m;++j)
            cin>>a[i][j];
    }
    cout<<trau(1,1);
    return 0;
}