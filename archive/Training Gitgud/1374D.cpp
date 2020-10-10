#include <iostream>
#include <fstream>
#include <map>
using namespace std;
long long n,k;

int main()
{
    freopen("1374D.inp","r",stdin);
    freopen("1374D.out","w",stdout);
    long long t;
    cin>>t;
    while (t--)
    {
        map <long long,long long> cnt;
        cin>>n>>k;
        long long tmp=0;
        for (long long i=1;i<=n;++i)
        {
            long long x;
            cin>>x;
            if (x%k==0) continue;
            tmp=max(tmp,++cnt[k-x%k]);
        }
        long long res=0;
        for (auto v:cnt)
        {
            if (v.second==tmp) 
            {
                res=k*(tmp-1)+v.first+1;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}