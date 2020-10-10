#include <iostream>
#include <algorithm>
using namespace std;
int b[100004],c[100004],res[100004],d[100004];
pair <int,int> a[100004];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n+1;++i)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    for (int i=1;i<=n;++i)
    {
        cin>>b[i];
    }
    sort(1+a,2+a+n);
    sort(1+b,1+b+n);
    for (int i=1;i<=n;++i)
    {
        c[i]=max(c[i-1],max(a[i].first-b[i],0));
    }
    for (int i=n+1;i>=1;--i)
    {
        d[i]=max(d[i+1],max(a[i].first-b[i-1],0));
    }
    for (int i=1;i<=n+1;++i)
    {
        res[i]=max(c[i-1],d[i]);
    }
    for (int i=1;i<=n+1;++i)
        cout<<res[i]<<" ";
    return 0;
}