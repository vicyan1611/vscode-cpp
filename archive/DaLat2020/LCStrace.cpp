#include <iostream>
#include <fstream>
#define endl '\n'
using namespace std;
int f[1002][1002],a[1002],b[1002],n,cnt,m,res[1003];
void trace(int x,int y)
{
    if (x*y==0) return;
    if (a[x]==b[y])
    {
        res[cnt]=a[x];
        x--;
        y--;
        cnt--;
    } else if (f[x][y]==f[x-1][y]) x--; else y--;
    trace(x,y);
}
void traua(int i)
{
    if (i>n)
    {
        return;
    }
    for (int j=1;j<=m;++j)
        if (a[i]==b[j])
        {
            f[i][j]=f[i-1][j-1]+1;
        } else f[i][j]=max(f[i-1][j],f[i][j-1]);
    traua(i+1);
}
int main()
{
    //freopen("LCStrace.inp","r",stdin);
    //freopen("LCStrace.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    cin>>m;
    for (int i=1;i<=m;++i)
        cin>>b[i];
    traua(1);
    cout<<f[n][m]<<endl;
    cnt=f[n][m];
    int cnt_n=cnt;
    trace(n,m);
    for (int i=1;i<=cnt_n;i++)
        cout<<res[i]<<" ";
    return 0;

}