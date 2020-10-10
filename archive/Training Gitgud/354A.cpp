#include <iostream>
#include <fstream>
using namespace std;
long long a[100005],L[100005],R[100005];
int main()
{
   // freopen("354A.inp","r",stdin);
    long long n,l,r,Ql,Qr;
    cin>>n>>l>>r>>Ql>>Qr;
    for (long long i=1;i<=n;++i)
    {
        cin>>a[i];
        L[i]=a[i]*l;
        R[i]=a[i]*r;
    }
    for (long long i=1;i<=n;++i)
    {
        L[i]+=L[i-1];
    }
    for (long long i=n;i>=1;--i)
    {
        R[i]+=R[i+1];
    }
    long long res=1e9;
    for (long long i=1;i<=n+1;++i)
    {
        long long Lmem=i-1;
        long long Rmem=n-i+1;
        if (abs(Lmem-Rmem)>1)
        {
            long long energy=L[i-1]+R[i];
            if (Rmem>Lmem)
            {
                energy+=(Rmem-Lmem-1)*Qr;
            } else energy+=(Lmem-Rmem-1)*Ql;
            res=min(res,energy);
        } else
        {
            res=min(res,L[i-1]+R[i]);
        }
    }
    cout<<res;
    return 0;
}