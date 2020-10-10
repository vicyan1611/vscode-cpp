#include <iostream>
using namespace std;
int n,k,a[405],f[405][405] ,s[405];
int main()
{
    freopen("FLYCAR.inp","r",stdin);
    freopen("FLYCAR.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;++i)
        s[i]=s[i-1]+a[i];
    int h=0;
    for (int i=1;i<=n;++i)
    {
        h=max(h,a[i]);
        f[i][0]=i*h-s[i];
    }
    for (int j=1;j<=k;++j)
    {
        for (int i=1;i<=n;++i)
        {
            f[i][j]=1e9;
            int maxh=a[i];
            for (int u=i-1;u>=0;--u)
            {
                
                f[i][j]=min(f[i][j],f[u][j-1]+(i-u)*maxh-(s[i]-s[u]));
                maxh=max(maxh,a[u]);
            }
        }
    }
    cout<<f[n][k];
    return 0;
}