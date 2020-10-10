#include <iostream>
#include <fstream>
using namespace std;
int n,a[100005],f[100005],q;
int main()
{
    freopen("1189C.inp","r",stdin);
    freopen("1189C.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
        f[i]=f[i-1]+a[i];
    cin>>q;
    while (q--)
    {
        int l,r;
        cin>>l>>r;
        int sums=f[r]-f[l]+a[l];
        cout<<sums/10<<endl;
    }
}