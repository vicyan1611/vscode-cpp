// #include <iostream>
// using namespace std;
// long long n,L1,L2,a[1000005];
// long long f[1000005],ress[1000005],rem[1000005];
// long long trau(long long i)
// {
//     if (i>n) return 0;
//     long long &res=f[i];
//     if (res!=-1) return res;
//     res=0;
//     for (long long j=L1;j<=L2;++j)
//     {
//         int tmp=trau(i+j)+a[i+j];
//         if (res<tmp)
//         {
//             res=tmp;
//             rem[i]=i+j;
//         }
//     }
//     return res;
// }
// int main()
// {
//     cin>>n>>L1>>L2;
//     for (long long i=1;i<=n;++i)
//     {
//         cin>>a[i];
//     }
//     for (long long i=0;i<=n;++i)
//         f[i]=-1;
//     long long res=0;
//     int vst=-1;
//     for (long long i=1;i<=n;++i)
//     {
//         int tmp=trau(i)+a[i];
//         if (tmp>res)
//         {
//             res=tmp;
//             vst=i;
//         }
//     }
//     int x=vst;
//     int cnt=0;
//     while (x!=0)
//     {
//         ress[++cnt]=x;
//         x=rem[x];
//     }
//     cout<<res<<" "<<cnt<<endl;
//     for (int i=1;i<=cnt;++i)
//         cout<<ress[i]<<" ";
//     return 0;
// }
#include <iostream>
#include <deque>
#include <fstream>
using namespace std;                    
long long n,L1,L2,a[1000004],res,f[10000004],ress[1000004];
deque <long long> dq;
int main()
{
    //freopen("Gold.inp","r",stdin);
    //freopen("Gold.out","w",stdout);
    cin>>n>>L1>>L2;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    res=0;
    for (int i=L1+1;i<=n;++i)
    {
        int j=i-L1;
        while (!dq.empty()&&a[dq.back()]<a[j])
        {
            dq.pop_back();
        }
        dq.push_back(j);
        if (!dq.empty()&& i-dq.front() > L2)
        {
            dq.pop_front();
        }
        a[i] += a[dq.front()];
        f[i]=dq.front();
        if (res<a[i])
        {
            res=a[i];
            f[0]=i;
        }
    }
    int x=0;
    int cnt=0;
    while (f[x]!=0)
    {
        ress[++cnt]=f[x];
        x=f[x];
    } 
    cout<<res<<" "<<cnt<<endl;
    for (int i=cnt;i>=1;--i)
    {
        cout<<ress[i]<<" ";
    }
    return 0;   
}