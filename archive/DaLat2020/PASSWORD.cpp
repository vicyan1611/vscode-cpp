#include <iostream>
#include <stack>
using namespace std;
int n,m,a[1003],b[1003],f[1003][1003],rem[1003][1003];
stack <int> ress;
void trace(int x,int y)
{
    if (x*y<=0) return;
    if (a[x]==b[y])
    {
        ress.push(a[x]);
        x-=2;
        y-=2;
    } else if (f[x][y]==f[x-1][y]) x--; else y--;
    trace(x,y);
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int j=1;j<=m;++j)
        cin>>b[j];
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            if (a[i]==b[j])
            {
                f[i][j]=f[i-2][j-2]+1;
            } else f[i][j]=max(f[i-1][j],f[i][j-1]);
        }
    }
    cout<<f[n][m]<<endl;
    trace(n,m);
    while (!ress.empty())
    {
        cout<<ress.top()<<" ";
        ress.pop();
    }
    return 0;
}