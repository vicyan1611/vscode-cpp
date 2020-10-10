#include <iostream>
using namespace std;
int n,f[100005],h[100005];
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>h[i];
    for (int i=1;i<=n;++i)
        f[i]=1e9;
    f[1]=0;
    f[2]=abs(h[2]-h[1]);
    for (int i=3;i<=n;++i)
        f[i]=min(f[i-1]+abs(h[i]-h[i-1]),f[i-2]+abs(h[i]-h[i-2]));
    cout<<f[n];
}