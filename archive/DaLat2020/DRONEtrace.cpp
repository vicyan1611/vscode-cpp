#include <iostream>
using namespace std;
int n,k,a[1000004],c[1000004],rem[3004][104],f[3004][104],ress[1000004];
int trau(int i,int time)
{
    if (time<=k+1&&i==n) return 0;
    if (i>n||time>k) return -1e9;
    int &res=f[i][time];
    if (res!=-1) return res;
    res=-1e9;
    for (int j=i+1;j<=min(i+a[i],n);++j)
    {
        //res=max(res,trau(j,time+1)+c[j]);
        int tmp=trau(j,time+1)+c[j];
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
    cin>>n>>k;
    for (int i=1;i<=n;++i)
    {
        cin>>c[i];
    }
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for (int i=0;i<=3002;++i)
    {
        for (int j=0;j<=102;++j)
            f[i][j]=-1;
    }
    int tmp=trau(1,0)+c[1];
    int i=1,j=0;
    int cnt=0;
    int cnt1=0;
    while (rem[i][j]!=n)
    {
        cnt1++;
        ress[++cnt]=rem[i][j];
        i=rem[i][j];
        j++;
        if (cnt1>n)
        {
            cout<<-1;
            return 0;
        }
    }
    if (cnt>0)
    {
        cout<<tmp;
         cout<<tmp<<" "<<cnt<<endl;
         for (int i=1;i<=cnt;++i)
         {
             cout<<ress[i]<<" ";
         }
    } else cout<<-1;
    return 0;
}