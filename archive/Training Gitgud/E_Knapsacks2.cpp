#include <iostream>
using namespace std;
int N,W;
long long v[105],w[105],f[103][100005];
int main()
{
    cin>>N>>W;
    for (int i=1;i<=N;++i)
    {
        cin>>w[i]>>v[i];
    }
    for (int i=0;i<=N;++i)
        for (int j=0;j<=100003;++j)
            f[i][j]=1e18;
    f[0][0]=0;
    for (int i=1;i<=N;++i)
    {
        for (int j=0;j<=100000;++j)
        {
            if (j>=v[i])
            {
                f[i][j]=min(f[i-1][j-v[i]]+w[i],f[i-1][j]);
            } else f[i][j]=f[i-1][j];
        }
    }
    for (int i=100000;i>=0;--i)
    {
        if (f[N][i]<=W)
        {
            cout<<i;
            break;
        }
    }
    return 0;
}