#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n,a[505],f[505][100005];
int main()
{
    freopen("candy.inp","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n;
    int m=0;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        m+=a[i];
    }
    for (int i=0;i<=n;++i)
    {
        for (int j=0;j<=100005;++j)
            f[i][j]=-1;
    }
    f[0][0]=0;
    for (int i=1;i<=n;++i)
    {
        for (int j=0;j<=m;++j)
        {
            f[i][j]=f[i-1][j];
            if (f[i-1][j+a[i]]!=-1) f[i][j]=max(f[i][j],f[i-1][j+a[i]]+a[i]);
            if (f[i-1][abs(j-a[i])]!=-1) f[i][j]=max(f[i][j],f[i-1][abs(j-a[i])]+a[i]);
        }
    }
    cout<<m-(f[n][0]/2);
    return 0;
}