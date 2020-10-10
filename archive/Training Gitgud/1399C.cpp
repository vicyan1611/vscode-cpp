#include <iostream>
#include <fstream>
using namespace std;
int f[104];
int solve(int x)
{
    int ans=0;
    for (int i=1;x-i>=i;i++)
    {
        if (x-i==i)
        {
            ans+=f[i]/2;
            break;
        }
        ans+=min(f[i],f[x-i]);
    }
    return ans;
}
int main()
{
   // freopen("1399C.inp","r",stdin);
   // freopen("1399C.out","w",stdout);
    int T,n;
    cin>>T;
    while (T--)
    {
        cin>>n;
        for (int i=1;i<=2*n;++i)
            f[i]=0;
        for (int i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            f[x]++;
        }
        int res=0;
        for (int i=0;i<=2*n;++i)
        {
            res=max(res,solve(i));
        }
        cout<<res<<endl;
    }
    return 0;
}