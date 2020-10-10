#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int n,k,a[5005],f[5005];
int main()
{
    freopen("1003C.inp","r",stdin);
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
    {
        f[i]=f[i-1]+a[i];
    }
    double res=0;
    for (int i=1;i<=n-k+1;++i)
    {
        for (int j=i+k-1;j<=n;++j)
        {
            double tmp=(double) (f[j]-f[i]+a[i])/(j-i+1);
            if (res<tmp) res=tmp;
        }
    }
    cout<<fixed<<setprecision(18)<<res;
    return 0;
}