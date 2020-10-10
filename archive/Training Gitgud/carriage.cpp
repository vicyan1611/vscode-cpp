#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n,m,k,a[100005],b[100005],f[100005],b2_cnt,x[23];
pair <int,int> b2[11000006];
int bnrs(int z)
{
    int l=1,r=b2_cnt;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (b2[mid].first==z) return mid;
        if (b2[mid].first>z) r=mid-1;
        if (b2[mid].first<z) l=mid+1;
    }
    return -1;
}
void build()
{
    int sohang=0;
    int res=0;
    for (int i=1;i<=m;++i)
    {
        if (x[i]==1)
        {
            sohang++;
            res+=b[i];
        }
    }
    b2[++b2_cnt].first=res;
    b2[b2_cnt].second=sohang;
}
void bnr(int i)
{
    for (int j=0;j<=1;++j)
    {
        x[i]=j;
        if (i==m) build(); else bnr(i+1);
    }
}
bool cmp(pair <int,int> a,pair <int,int> b)
{
    if (a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
int main()
{
    freopen("carriage.inp","r",stdin);
    freopen("carriage.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        cout<<a[i]<<" ";
    }
    f[0]=0;
    for (int i=1;i<=n;i++)
    {
        f[i]=f[i-1]+a[i];
    }
    cout<<endl;
    for (int i=1;i<=m;++i)
    {
         cin>>b[i];
         cout<<b[i]<<" ";
    }
    cout<<endl;
    bnr(1);
    sort(1+b2,1+b2+b2_cnt,cmp);
    int vt=-1,vt2=-1;
    int res=1e9;
    for (int i=n;i>=1;--i)
    {
        vt=bnrs(k-f[i]);
        if (vt!=-1)
        {
            vt2=i;
            while (b2[vt-1].first==b2[vt].first&&b2[vt-1].second<=b2[vt].second) vt--;
            res=min(res,n-vt2+b2[vt].second);
        }
    }
    cout<<res;
    return 0;
}