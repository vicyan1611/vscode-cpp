#include <iostream>
#include <fstream>
using namespace std;
char s[205];
int f[205][205][205]; 
int main()
{
    freopen("CUTSEQ.inp","r",stdin);
    freopen("CUTSEQ.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>s[i];
    }
    for (int i=0;i<=n;++i)
        f[i][i][0]=1;
    for (int i=1;i<n;++i)
    {
        for (int j=i+1;j<=n;++j)
        { 
            int k=0;
            for (int z=j+1;z<=n;++z)
            {
                if (s[z]==s[j]) k++; else break;
            }
            int tmp_TH1=f[i][j-1][0]+(k+1)*(k+1);
            int tmp_TH2=0;
            for (int u=j-1;u>=i;--u)
            {
                if (s[u]==s[j]) tmp_TH2=max(tmp_TH2,f[u+1][j-1][0]+f[i][u][k+1]);
            }
            f[i][j][k]=max(tmp_TH1,tmp_TH2);
            cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<endl;
        }
    }
    cout<<f[1][n][0];
    return 0;
}