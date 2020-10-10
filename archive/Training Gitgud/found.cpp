#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n,a[100005];
int bnrs(int x)
{
    int l=1,r=n;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (a[mid]==x) return mid;
        if (a[mid]>x) r=mid-1;
        if (a[mid]<x) l=mid+1;
    }
    return -1;
}
int main()
{
    freopen("found.inp","r",stdin);
    freopen("found.out","w",stdout);
    int m;
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    sort(1+a,1+a+n);
    while (m--)
    {
        int h;
        cin>>h;
        int vt=bnrs(h);
        if (vt==-1) cout<<0<<endl; else cout<<1<<endl;
    }
    return 0;
}