#include <iostream>
using namespace std;
pair <int,int> b[100004];
int a[100004];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    int m=0;
    for (int i=1;i<=n;++i)
    {
        if (a[i]!=b[m].first)
        {
            b[++m].first=a[i];
            b[m].second++;
        } else
        {
            b[m].second++;
        }
    }
    int res=1e9;
    for (int i=2;i<=m-1;++i)
    {
        if (b[i].first>b[i-1].first&&b[i].first>b[i+1].first) res=min(res,b[i].second+2);
    }
    if (res==1e9) cout<<0; else cout<<res;
    return 0;
}