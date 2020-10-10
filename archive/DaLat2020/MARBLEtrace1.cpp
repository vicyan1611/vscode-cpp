#include <iostream>
using namespace std;
int W,H,n,w[205],h[205],innput[605][605],f[605][605],minw,minh;
int trau(int x,int y)
{
    if (innput[x][y]) return 0;
    if (x<minw||y<minh) return x*y;
    int &res=f[x][y];
    if (res!=-1) return res;
    for (int i=1;i<=n;++i)
    {
        if (w[i]<=x)
        {
            int tmp_min_w
        }
    }

}
int main()
{
    cin>>W>>H>>n;
    minw=1e9;
    minh=1e9;
    for (int i=1;i<=n;++i)
    {
        cin>>w[i]>>h[i];
        minw=min(minw,w[i]);
        minh=min(minh,h[i]);
        innput[w[i]][h[i]]=1;
    }
    for (int i=0;i<=603;++i)
        for (int j=0;j<=603;++j)
            f[i][j]=-1;
    cout<<trau(W,H);
    return 0;
}