#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    freopen("TEA.inp","r",stdin);
    freopen("TEA.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cout<<m<<endl;
    for (int i=1;i<=n;++i)
    {
        if (i%2==0) cout<<"S"; else cout<<"C";
    }
    return 0;
}