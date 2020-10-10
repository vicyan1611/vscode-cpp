#include <iostream>
using namespace std;
long long c[8]=
{
    8,4,2,1,10,9,0,5
};
long long a[5][10004],f[10004][14],n;
long long val(long long i,int vt)
{
    long long res=0;
    for (long long j=0;j<4;++j)
    {
        res+=((vt>>j)&1)*a[j][i];
    }
    return res;
}
long long trau(long long i,int used)
{
    if (i==n) return 0;
    long long &res=f[i][used];
    if (res!=-1) return res;
    res=0;
    for (long long j=0;j<8;++j)
    {
        if ((c[j]&used)!=0) continue;
        res=max(res,val(i,c[j])+trau(i+1,c[j]));
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i=0;i<=10002;++i)
    {
        for (int j=0;j<=12;++j)
            f[i][j]=-1;
    }
    long long Max=-1e18;
    cin>>n;
    for (long long i=0;i<4;++i)
        for (long long j=0;j<n;++j)
        {
            cin>>a[i][j];
            Max=max(Max,a[i][j]);
        }
            
    if (trau(0,0)==0) cout<<Max; else cout<<trau(0,0);
    return 0;
}