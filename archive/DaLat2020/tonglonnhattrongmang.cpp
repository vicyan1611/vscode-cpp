#include <iostream>
using namespace std;
int f[1003],n,a[1003],res;
int trau(int i)
{
    if (i==1) return a[1];
    if (f[i]!=-1) return f[i];
    f[i]=0;
    f[i]=max(a[i],trau(i-1)+a[i]);
    res=max(res,f[i]);
    return f[i];
}
int main()
{
    cin>>n;
    res=0;
    for (int i=1;i<=n;++i)
        f[i]=-1;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    int tmp=trau(n);
    cout<<res;
    cin>>n;
    return 0;
}