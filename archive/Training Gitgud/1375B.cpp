#include <iostream>
#include <fstream>
using namespace std;
int a[305][305],n,m,t;
bool check()
{
    if (a[1][1]>2||a[n][m]>2||a[n][1]>2||a[1][m]>2)
    {
        return false;
    }
    for (int i=2;i<n;++i)
    {
        if (a[i][1]>3||a[i][m]>3) return false;
    }
    for (int i=2;i<m;++i)
    {
        if (a[1][i]>3||a[n][i]>3) return false;
    }
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            if (i>1&&i<n&&j>1&&j<m) if (a[i][j]>4) return false;
        }
    }
    return true;
}
int main()
{
   // freopen("1375B.inp","r",stdin);
   // freopen("1375B.out","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        for (int i=1;i<=n;++i)
        {
            for (int j=1;j<=m;++j)
                cin>>a[i][j];
        }
        if (check()==false)
        {
            cout<<"NO"<<endl;
        } else
        {
            cout<<"YES"<<endl;
            for (int i=1;i<=n;++i)
            {
                for (int j=1;j<=m;++j)
                {
                    if ((i==1&&j==1)||(i==1&&j==m)||(i==n&&j==1)||(i==n&&j==m)) cout<<"2 "; else 
                    if (((i!=1&&i!=n)&&(j==1||j==m))||((i==1||i==n)&&(j!=1&&j!=m))) cout<<"3 "; else cout<<"4 ";
                }
                cout<<endl;
            }
        }
        
    }
    return 0;
}