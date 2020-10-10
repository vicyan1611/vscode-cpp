#include <iostream>
#define md 1000000007
using namespace std;
bool a[23][23];
long long f[23][2200000];
long long n;
long long trau(long long i,long long used)
{
    if (i==n) return 1;
    long long &res=f[i][used];
    if (res!=-1) return res;
    res=0;
    for (long long j=0;j<n;++j)
    {
        if (a[i][j]==0||(used>>j)&1) continue;
        res=(res+trau(i+1,used|(1<<j)))%md;
    }
    return res;
}   
int main()
{
    for (int i=0;i<=22;++i)
        for (int j=0;j<=2199999;++j)
        {
            f[i][j]=-1;
        }
    cin>>n;
    for (long long i=0;i<n;++i)
    {
        for (long long j=0;j<n;++j)
        {
            cin>>a[i][j];
        }
    }
    cout<<trau(0,0);   
    return 0;
}