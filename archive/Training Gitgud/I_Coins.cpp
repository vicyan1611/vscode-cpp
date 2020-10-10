#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
int n;
double a[3005],f[3000][3000];
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    f[0][0]=1;
    for (int i=1;i<=n;++i)
    {
        f[i][0]=f[i-1][0]*(1-a[i]);
        for (int j=1;j<=i;++j)
        {
            f[i][j]=(f[i-1][j]*(1-a[i]))+(f[i-1][j-1]*a[i]);
        }
    }
    double res=0;
    int tmp=(n+1)/2;
    for (int i=n;i>=tmp;--i)
    {
        res+=f[n][i]; 
    }
    cout<<setprecision(9)<<fixed<<res;
    return 0;
}