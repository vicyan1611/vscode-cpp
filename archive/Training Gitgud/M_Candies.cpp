//Vinh chep code cua nhi quoc gia, dung chui Vinh hu hu :(
#include <iostream>
#define md 1000000007
using namespace std;
long long n,k,a[100005],f[105][100005];
int main()
{
    cin>>n>>k;
    for (long long i = 1; i <= n; ++i)
        cin>>a[i];
    for (long long i = 0; i <= k; i++)
    {
        f[0][i]=1;
    }
    
    for (long long i = 1; i <= n; ++i)
    {
        for (long long j = 0; j <= k; ++j)
        {
            if (j <= a[i])
            {
                f[i][j]+=f[i-1][j];
                if (f[i][j]>md) f[i][j]-=md;
            } else
            {
                long long tmp= f[i-1][j] - f[i-1][j-a[i]-1];
                tmp%=md;
                if (tmp < 0) tmp+=md;
                f[i][j]+=tmp;
                if (f[i][j]>md) f[i][j]-=md;
            }
            if (j>0) f[i][j]+=f[i][j-1];
            if (f[i][j]>md) f[i][j]-=md;
        }
    }
    if (k == 0)
    {
        cout<<1;
        return 0;
    }
    long long res=f[n][k]-f[n][k-1];
    if (res<0) res+=md;
    cout<<res;
    return 0;
}