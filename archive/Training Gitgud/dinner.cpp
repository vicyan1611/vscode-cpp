#include <iostream>
#include <fstream>
#define md 1000000007
using namespace std;
long long f[1000006];
int main()
{
    freopen("dinner.inp","r",stdin);
    freopen("dinner.out","w",stdout);
    long long t;
    f[1]=1;
    f[2]=1;
    for (long long i=3;i<=1000006;++i)
    f[i]=(f[i-1]+f[i-2]*(i-2))%md;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        cout<<f[n]<<endl;
    }
    return 0;
}