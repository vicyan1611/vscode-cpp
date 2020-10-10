#include <iostream>
using namespace std;
int n,T,D,a[10003],t[10003],f[10003][105],rem[10003][10003],ress[10003];
int trau(int i,int time)
{
    if (time>T) return -1e9;
    if (i>n) return 0;
    int &res=f[i][time];
    if (res!=-1) return res;
    res=0;
    for (int j=i+1;j<=i+D;++j)
    {
        int tmp=trau(j,time+t[j])+a[j];
        if (tmp>res)
        {
            res=tmp;
            rem[i][time]=j;
        }
    } 
    return res;
}
int main()
{
    cin>>n>>T>>D;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=0;i<=10001;++i)
        for (int j=0;j<=103;++j) f[i][j]=-1;
    for (int i=1;i<=n;++i)
        cin>>t[i];
    int res=0,vts=0;
    for (int i=1;i<=n;++i)
    {
        int tmp=trau(i,t[i])+a[i];
        if (res<tmp)
        {
            res=tmp;
            rem[0][0]=i;
            
        }
    }
    int cnt=0;
    int time=0;
    while (rem[vts][time]>0)
    {
        ress[++cnt]=rem[vts][time];
        vts=rem[vts][time];
        time+=t[vts];
    }
    cout<<res<<" "<<cnt<<endl;
    for (int i=1;i<=cnt;++i)
        cout<<ress[i]<<" ";
    return 0;
}