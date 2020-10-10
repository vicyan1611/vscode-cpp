#include <iostream>
#include <fstream>
using namespace std;
char a[2005][2005];
int n,m;
int f[2005];
int main()
{
   freopen("985B.inp","r",stdin);
   freopen("985B.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            cin>>a[i][j];
            if (a[i][j]=='1') f[j]++;
        }
    }
    for (int i=1;i<=m;++i)
        cout<<f[i]<<" ";
    for (int i=1;i<=n;++i)
    {
        bool check=true;
        for (int j=1;j<=m;++j)
            {
                if (a[i][j]=='1') if (f[j]==1) check=false;
            }
        if (check)
        {
            cout<<"YES";
            return 0;
        }
            
    }
    cout<<"NO";
}