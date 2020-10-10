#include <iostream>
using namespace std;
long long w[103],v[103],f[103][100005];
int main()
{
    long long N,W;
    cin>>N>>W;
    for (long long i=1;i<=N;++i)
    {
        cin>>w[i]>>v[i];
    }
    for (long long i=1;i<=N;++i)
    {
        for (long long j=0;j<=W;++j)
        {
            if (j>=w[i])
            {
                f[i][j]=max(f[i-1][j-w[i]]+v[i],f[i-1][j]);
            } else f[i][j]=f[i-1][j];
        }
    }
    cout<<f[N][W];
    return 0;
}
