#include <iostream>
#include <fstream>
#define oo 1e18
using namespace std;
int bnr(int, x,int l,int r)
{
    int k=oo;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (b[mid]==x)
        {
            return b[mid];
        } 
    }
    return k;

}
int main()
{
    freopen("HALOWEEN.INP","r",stdin);
    freopen("HALOWEEN.OUT","w",stdout);
    cin>>N>>M>>P>>T>>B;
    for (int i=1;i<=M;++i)
    {
        cin>>h[i].first;
        h[i].second=1e9;
    }
        
    for (int i=1;i<=P;++i)
        cin>>b[i];
    sort(1+h,1+h+M);
    int j=1;
    for (int i=1;i<=M;++i)
    {
        pre=res;
        res=min(res,a)
    }
    return 0;
}