#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n,a[10004];
pair <int,int> b[10004];
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    int res=0;
    sort(1+a,1+a+n);
    int m=0;
    for (int i=1;i<=n;++i)
    {
        if (b[m].first!=a[i])
        {
            b[++m].first=a[i];
            b[m].second++;
        } else b[m].second++;
    }
    res=0;
    for (int i=1;i<m;++i)
    {
        if (b[i+1].first-b[i].first==1)
        {
            int tmp=min(b[i].second,b[i+1].second);
            res+=tmp;
            b[i].second-=tmp;
            b[i+1].second-=tmp;
            if (b[i].second>0) res+=b[i].second;
            b[i].second=0;
        }
    }
    cout<<res;
    return 0;
}