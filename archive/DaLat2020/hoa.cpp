#include <iostream>
#include <fstream>
using namespace std;
int a[10004],b[10004];
int main()
{
    freopen("hoa.inp","r",stdin);
    freopen("hoa.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    if (n&1)
    {
        int res=0;
        for (int i=1;i<=n;++i) res+=(a[i]&1)?a[i]:a[i]-1;
        cout<<res;
        return 0;
    }
    int minn=0;
    int res=0;
    for (int i=1;i<=n;++i)
    {
        if (a[i]&1)
        {
            minn=min(minn,a[i]);
            res+=a[i];
        } else
        {
            minn=min(a[i]-1,minn);
            res+=a[i-1];
        }
    }
    cout<<res-minn;
    return 0;
}