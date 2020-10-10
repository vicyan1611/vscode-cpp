#include <iostream>
using namespace std;
long long a[10004],n,f[3005][3005];
long long trau(int l,int r,int turn)
{
    if (r<l) return 0;
    if (r==l) return a[l]*turn;
    long long &res=f[l][r];
    if (res!=-1) return res;
    if (turn==1)
    {
        res=0;
        res=max(trau(l,r-1,-1)+a[r],trau(l+1,r,-1)+a[l]);
    } else
    {
        res=1e18;
        res=min(trau(l+1,r,1)-a[l],trau(l,r-1,1)-a[r]);
    }
    return res;
}
int main()
{
    cin>>n;
    for (long long i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j) f[i][j]=-1;
    cout<<trau(1,n,1);
    return 0;
}