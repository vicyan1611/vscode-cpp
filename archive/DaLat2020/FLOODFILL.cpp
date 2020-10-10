#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n,a[50005],f[5005][5005],g[5005][5005];
int main()
{
    freopen("FLOODFILL.inp","r",stdin);
    freopen("FLOODFILL.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    n=unique(a+1,a+n+1)-a-1;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            f[i][j]=1e9;
    for (int i=1;i<=n;++i)
        f[i][i]=0;
    for (int i=n;i>=1;--i)
    {
        for (int j=i+1;j<=n;++j)
        {
            f[i][j]=1e9;
            int L=i;
            int R=j;
            f[L][R]=min(f[L+1][R]+(a[L+1]!=a[L]),g[L+1][R]+(a[R]!=a[L]));
            g[L][R]=min(g[L][R-1]+(a[R-1]!=a[R]),f[L][R-1]+(a[L]!=a[R]));
        }
    }
    cout<<min(g[1][n],f[1][n]);
    return 0;
}