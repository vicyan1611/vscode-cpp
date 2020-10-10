#include <iostream>
#include <fstream>
using namespace std;
long long n,a[1000005],P,f[1000005];
int main()
{
    freopen("average.inp","r",stdin);
    freopen("average.out","w",stdout);
    cin>>n;
    for (long long i=1;i<=n;++i)
        cin>>a[i];
    cin>>P;

    for (long long i=1;i<=n;++i)
    {
        f[i]=f[i-1]+a[i];
    }
    if (n<10004)
    {
        long long res=0;
        for (long long i=1;i<=n;++i)
            for (long long j=i;j<=n;++j)
            {
                long long tong=f[j]-f[i]+a[i];
                if (tong/(j-i+1)>=P) res++;
            }
        cout<<res;
        return 0;
    }
    long long j=1,res=0;
    long long i=1;j=1;
    while (i<=n&&j<=n)
    {
        long long prei=i;
        long long prej=j;
        long long tong=f[j]-f[i]+a[i];
        if (tong/(j-i+1)>=P) 
        {
            res++;
            j++;
        } else 
        {
            if (i<j)
            {
                while (i<j)
                {
                    long long tong=f[j]-f[i]+a[i];
                    if (tong/(j-i+1)>=P)
                    {
                        break;
                    } else i++;
                }
            } else if (i==j) 
            {
                while (j<n)
                {
                    long long tong=f[j]-f[i]+a[i];
                    if (tong/(j-i+1)>=P)
                    {
                        break;
                    } else j++;
                }
            }
        }
        if (i==prei&&j==prej) break;
    }
    if (i<n)
    {
        i++;
        for (i;i<=n;++i)
        {
            long long tong=f[n]-f[i]+a[i];
            if (tong/(n-i+1)>=P) res++;
        }
    } 
    cout<<res;
    return 0;
}