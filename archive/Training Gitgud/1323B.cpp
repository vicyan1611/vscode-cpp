#include <iostream>
#include <fstream>
using namespace std;
int a[40003],n,m,k,b[40004],c[40004],d[40004];
int main()
{
    freopen("1323B.inp","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        c[i]=a[i];
        a[i]=a[i-1]+a[i];
    }
    for (int i=1;i<=m;++i)
    {
        cin>>b[i];
        d[i]=b[i];
        b[i]=b[i-1]+b[i];
    }
    long long res=0;
    for (int j=1;j*j<=k;++j)
    {
        if (k%j==0)
        {
            int x=j;
            int cnt_a=0;
            for (int i=x;i<=n;++i)
            {
                if ((a[i]-a[i-x+1]+(c[i-x+1]==1))==x)
                {
                    cnt_a++;
                }
            }
            int y=k/x;
            int cnt_b=0;
            for (int i=y;i<=m;++i)
            {
                if ((b[i]-b[i-y+1]+(d[i-y+1]==1))==y)
                {
                    cnt_b++;
                }
            }
            res+=cnt_a*cnt_b;
            if (x==y) continue;
             x=k/j;
             cnt_a=0;
            for (int i=x;i<=n;++i)
            {
                if ((a[i]-a[i-x+1]+(c[i-x+1]==1))==x)
                {
                    cnt_a++;
                }
            }
             y=k/x;
             cnt_b=0;
            for (int i=y;i<=m;++i)
            {
                if ((b[i]-b[i-y+1]+(d[i-y+1]==1))==y)
                {
                    cnt_b++;
                }
            }
            res+=cnt_a*cnt_b;
        }
    }
    cout<<res;
    return 0;
}