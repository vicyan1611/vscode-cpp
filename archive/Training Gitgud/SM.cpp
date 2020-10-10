#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const long long md=1000000007;
string s,t;
long long cnt_res,res[1000006],hashB,hashA[1000005],poww[1000005];
long long hash_cal(long long i,long long j)
{
    return ((hashA[j]-hashA[i-1]*poww[j-i+1]+md*md)%md);
}
int main()
{
    freopen("SM.inp","r",stdin);
    freopen("SM.out","w",stdout);
    cin>>s>>t;
    long long m=s.size();
    long long n=t.size();
    s=" "+s;
    t=" "+t;
    long long hashB=0;
    for (long long i=1;i<=m;++i)
    {
        hashB=(hashB*27+(s[i]-64))%md;
    }
    hashA[0]=0;
    for (long long i=1;i<=n;++i)
    {
        hashA[i]=(hashA[i-1]*27+(t[i]-64))%md;
    }
    poww[0]=1;
    for (long long i=1;i<=n;++i)
    {
        poww[i]=(poww[i-1]*27)%md;
    }
    long long cnt_res=0;
    for (long long i=1;i<=n-m+1;++i)
    {
        if (hashB==hash_cal(i,i+m-1)) 
        {
            cnt_res++;
            res[cnt_res]=i;
        } 
    }
    cout<<cnt_res<<endl;
    for (long long i=1;i<=cnt_res;++i)
    {
        cout<<res[i]-1<<" ";
    }
    return 0;
}