#include <iostream>
using namespace std;
long long n,md,a[100004],sums[1000004], p[100004];
int main()
{
    cin>>n>>md;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        sums[i]=sums[i-1]+a[i];
    }
    int res=0;
    for (int i=1;i<=n;++i)
    {
        p[i]=a[i]*sums[i-1];
    }
    for (int i=1;i<=n;++i)
    {
        sums[i]=sums[i-1]+p[i];
    }
    res=0;
    for (int i=n;i>=3;--i)
    {
        res+=a[i]*sums[i-1];
    }
    cout<<res;
    return 0;
}