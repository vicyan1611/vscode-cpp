#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
int n;
float a[20][20],f[20][1<<20];
float trau(int i, int used)
{
    if (i==n) return 1;
    float &res=f[i][used];
    if (res!=0) return res;
    for (int j = 0; j < n; j++)
    {
        if (((used>>j)&1)==1) continue;
        res=max(res,trau(i+1,used|(1<<j))*a[i][j]);
    }
    return res;
}
int main()
{
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>a[i][j];
            a[i][j]/=100;
        }
    }
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            f[i][j]=0;
        }
        
    }
    cout<<f[1][1]<<endl;
    cout<<fixed<<setprecision(11)<<trau(0,0)*100;   
    return 0;
}