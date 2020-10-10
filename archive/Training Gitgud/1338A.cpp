//https://codeforces.com/contest/1338/problem/A
#include <fstream>
#include <iostream>
#define endl '\n'
using namespace std;
long long tmp[100005],a[100005],n;
bool checkk(long long x)
{
    long long sums=1;
    for (long long i=1;i<=x;++i)
        sums*=2;
    --sums;
    for (long long i=1;i<=n;++i)
        tmp[i]=a[i];
    tmp[n]+=sums;
    for (long long i=n-1;i>=1;--i)
    {
        if (tmp[i]>tmp[i+1]) return false;
        tmp[i]+=sums;
        tmp[i]=min(tmp[i],tmp[i+1]);
    }
    return true;
}
long long bnrs()
{
    long long l=0,r=60,e;
    while (l<=r)
    {
        long long mid=(l+r)/2;
        if (checkk(mid))
        {
            e=mid;
            r=mid-1;
        } else l=mid+1;
    }
    return e;
}
int main()
{
    freopen("1338A.inp","r",stdin);
    long long t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (long long i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        cout<<bnrs()<<endl;
    }
    return 0;
}