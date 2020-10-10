#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
long long k,n,res=0,a[200005],b[200005],f[200005];
string st;
/*void trau(long long i,long long cnt,long long sums)
{
    if (cnt>k) return;
    if (i>n)
    {
        res=max(res,sums);
        return;
    }
    if (st[i+1]==st[i])
    {
        if (cnt<k) trau(i+1,cnt+1,sums+a[i+1]);
        trau(i+1,cnt,sums);
    }else
    {
        trau(i+1,1,sums+a[i+1]);
        trau(i+1,0,sums); 
    }
    return;
}*/
int main()
{
   // freopen("1107C.inp","r",stdin);
    cin>>n>>k;
    for (long long i=1;i<=n;++i)
        cin>>a[i];
    for (long long i=1;i<=n;++i)
    {
        f[i]=f[i-1]+a[i];
    }
    cin>>st;
    st=" "+st;  
    /*trau(1,1,a[1]);
    trau(1,0,0);
    cout<<res;*/
    long long l=1,r=1;
    long long d=0;
    long long res=0;
    while (r<=n)
    {
        while (st[r]==st[l]&&r<=n)
        {
           
            d++;
            b[d]=a[r];
            r++;
        }
        r--;
        if (r-l+1<=k) 
        {
            res+=f[r]-f[l]+a[l];
            d=0;
        } else
        {
            sort(1+b,1+b+d,greater<long long>());
            for (long long i=1;i<=k;++i)
            {
                res+=b[i];
            }
                
            d=0;
        } 
        l=++r;
    }
    cout<<res;
    return 0;

}