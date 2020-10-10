#include <iostream>
#include <cstdio>
#include <algorithm>
#include <fstream>
#define oo 2e9
using namespace std;
int n,a[100004],b[100004],ress[1000003],f[100004];
void trace(int cnt)
{
    for (int i=n;i>=1;--i)
    {
        if (f[i]==cnt)
        {
            ress[cnt]=i;
            cnt--;
        }
    }
}
int main()
{
    freopen("LIStrace.inp","r",stdin);
    freopen("LIStrace.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
        b[i]=oo;
    //b[0]=-oo;
    int res=0;
    for (int i=1;i<=n;++i)
    {
        f[i]=upper_bound(b+1,b+1+res,a[i])-b;
        b[f[i]]=a[i];
        res=max(res,f[i]);
    }
    cout<<res<<endl;
    // int cnt=res;
    // trace(cnt);
    // for (int i=1;i<=res;++i)
    // {
    //     cout<<ress[i]<<" ";
    // }
    return 0;
}