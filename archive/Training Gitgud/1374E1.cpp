#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
long long n,k,c[200005],a[200005],b[200005],res;
int main()
{
   // freopen("1374E1.inp","r",stdin);
   // freopen("1374E1.out","w",stdout);
    cin>>n>>k;
    long long na=0,nb=0,nc=0;
    while (n--)
    {
        long long t,x,y;
        cin>>t>>x>>y;
        if (x==1&&y==1)
        {
            c[++nc]=t;
        }
        if (x==1&&y==0)
        {
            a[++na]=t;
        }
        if (x==0&&y==1)
        {
            b[++nb]=t;
        }
    }
    sort(1+a,1+a+na);
    sort(1+b,1+b+nb);
    sort(1+c,1+c+nc);
    for (long long i=1;i<=na;++i)
        a[i]=a[i-1]+a[i];
    for (long long i=1;i<=nb;++i)
        b[i]=b[i-1]+b[i];
    for (long long i=1;i<=nc;++i)
        c[i]=c[i-1]+c[i];
    res=1e18;
    for (long long i=0;i<=nc;++i)
    {
        long long j=k-i;
        if (j<=na&&j<=nb&&j>=0)
        {
            res=min(res,c[i]+a[j]+b[j]);
        }
    }
    if (res==1e18) cout<<-1; else cout<<res;
    return 0;
}