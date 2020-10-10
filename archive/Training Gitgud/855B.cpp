#include <iostream>
#include <fstream>
using namespace std;
long long a[100005];
long long dp[5][100005];
int main()
{
  // freopen("855B.inp","r",stdin);
    long long p,q,r,n;
    cin>>n>>p>>q>>r;
    for (int i=1;i<=3;++i)
    {
        for (int j=0;j<=n+1;++j)
        {
            dp[i][j]=-55e18;
        }
    }
    for (long long i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for (long long i=n;i>=1;--i)
    {
        dp[1][i]=max(dp[1][i],max(dp[1][i+1],r*a[i]));
    }
    for (long long i=n;i>=1;--i)
    {
        dp[2][i]=max(dp[2][i],max(dp[2][i+1],q*a[i]+dp[1][i]));
    }
    for (long long i=n;i>=1;--i)
    {
        dp[3][i]=max(dp[3][i],max(dp[3][i+1],dp[2][i]+p*a[i]));
    }
    cout<<dp[3][1];
    return 0;
}