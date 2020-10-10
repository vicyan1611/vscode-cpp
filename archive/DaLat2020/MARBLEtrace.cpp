#include <iostream>
#include <fstream>
using namespace std;
int W,H,n,w[205],h[205],innput[605][605],minw,minh,f[605][605];
int trau(int x,int y)
{
    if (innput[x][y]>0) return 0;
    if (x<minw||y<minh) return x*y;
    int &res=f[x][y];
    if (res!=-1) return res;
    res=1e9;
    for (int i=1;i<=n;++i)
    {
        if (w[i]<=x) res=min(res,trau(w[i],y)+trau(x-w[i],y));
        if (h[i]<=y) res=min(res,trau(x,h[i])+trau(x,y-h[i]));
    }
    return res;
}
int main()
{
  //  freopen("MARBLE.inp","r",stdin);
  //  freopen("MARBLE.out","w",stdout);
    cin>>W>>H>>n;
    minw=1e9;
    minh=1e9;
    for (int i=1;i<=n;++i)
    {
        cin>>w[i]>>h[i];
        innput[w[i]][h[i]]=i;
        minw=min(minw,w[i]);
        minh=min(minh,h[i]);
    }
    for (int i=0;i<=W;++i)
    {
        for (int j=0;j<=H;++j)
            f[i][j]=-1;
    }
    cout<<trau(W,H);
    return 0;
}