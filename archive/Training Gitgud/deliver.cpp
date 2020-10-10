#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
pair <long long,long long> a[100005];
long long n,m,res;
int main()
{
    freopen("deliver.inp","r",stdin);
    freopen("deliver.out","w",stdout);
    cin>>n>>m;
    for (long long i=1;i<=n;++i)
    {
        cin>>a[i].first>>a[i].second;
    }
    long long i=n;
    res=0;
    while (i>=1)
    {
        if (a[i].second<=0)
        {
            i--;
            continue;
        }
        long long cnt=a[i].second/m;
        a[i].second-=cnt*m;
        res+=a[i].first*2*cnt;
        if (a[i].second>0)
        {
            long long tmp_m=m-a[i].second;
            a[i].second=0;
            res+=a[i].first*2;
            for (long long j=i-1;j>=1;j--)
            {
                long long tmp=min(tmp_m,a[j].second);
                a[j].second-=tmp;
                tmp_m-=tmp;
                if (tmp_m==0) break;
            }
        }       
    }
    cout<<res;
    return 0;
}