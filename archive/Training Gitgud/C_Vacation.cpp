#include <iostream>
using namespace std;
long long n,f[100005][4],a[100005][4];
int main()
{
    cin>>n;
    for (long long i=1;i<=n;++i)
    {
        cin>>a[i][1]>>a[i][2]>>a[i][3];
    }
    f[1][1]=a[1][1];
    f[1][2]=a[1][2];
    f[1][3]=a[1][3];
    for (long long i=2;i<=n;++i)
    {
        for (long long j=1;j<=3;++j)
        {
            if (j==1)
            {
                f[i][j]=max(f[i-1][2],f[i-1][3])+a[i][j];
            } else if (j==2)
            {
                f[i][j]=max(f[i-1][1],f[i-1][3])+a[i][j];
            } else if (j==3)
            {
                f[i][j]=max(f[i-1][1],f[i-1][2])+a[i][j];
            }
        }
    }
    cout<<max(f[n][1],max(f[n][2],f[n][3]));
    return 0;
}