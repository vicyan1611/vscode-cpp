#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
long long n,c,k,b[1000004];
pair <long long,long long> a[1000004];
int main()
{
    freopen("OLYMP.inp","r",stdin);
    freopen("OLYMP.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>c>>k;
    for (long long i=1;i<=n;++i)
    {
        cin>>a[i].first>>a[i].second;
    }
    long long cnt_n=0;
    long long res=0;
    for (long i=1;i<=n;++i)
    {
        if (k-a[i].first>0)
        {
            if (a[i].second==0)
            {   
                b[++cnt_n]=1e18;
            } else
            if ((k-a[i].first)%a[i].second==0)
            {
                b[++cnt_n]=(k-a[i].first)/a[i].second;
            } else
            {
                b[++cnt_n]=(k-a[i].first)/a[i].second+1;
            }
            
        } else res++;
    } 
    sort(1+b,1+b+cnt_n);
    for (long long i=1;i<=cnt_n;++i)
    {
        if (c>=b[i]) 
        {
            c-=b[i];
            res++;
        } else break;
    }
    cout<<res;
    return 0;
}