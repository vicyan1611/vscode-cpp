#include <iostream>
using namespace std;
int n,k,h[100005],f[100005];
int main()
{
    cin>>n>>k;
    for (int i=1;i<=n;++i)
    {
        cin>>h[i];
    }
    f[1]=0;
    f[0]=0;
    for (int i=2;i<=n;++i)
    {
        f[i]=1e9;
        int l=i-k;
        l=max(l,1);
        for (int j=i-1;j>=l;--j)
        {
            f[i]=min(f[i],f[j]+abs(h[i]-h[j]));
        }
    }
    cout<<f[n];
    return 0;
}