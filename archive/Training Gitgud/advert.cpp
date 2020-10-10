#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int n;
double w,h,a[100005],b[100005];
bool checkk(double k)
{
    double hh=0;
    double ww=0;
    for (int i=1;i<=n;++i)
    {
        if (b[i]==b[i-1])
        {
            if (ww==0)
            {
                hh+=b[i]*k;
            }
            ww+=a[i]*k;
        } else
        {
            hh+=b[i]*k;
            ww=a[i]*k;
        }
        if (ww>=w)
        {
            if (ww==w)
                ww=0; else
                {
                    ww=a[i]*k;
                    hh+=b[i]*k;
                }
        }
        if (ww>w||hh>h) return false;
    }
    return true;
}
double bnrs()
{
    double l=0,r=2e13,e;
    while (r-l>=1e-7)
    {
        double mid=(l+r)/2;
        if (checkk(mid))
        {
            e=mid;
            l=mid+0.0000001;
        } else r=mid-0.0000001;
    }
    return e;
}
int main()
{
    freopen("advert.inp","r",stdin);
    freopen("advert.out","w",stdout);
    cin>>n>>w>>h;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i]>>b[i];
    }
    cout<<fixed<<setprecision(6)<<bnrs();
    return 0;
}