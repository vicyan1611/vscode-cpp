#include <iostream>
#include <fstream>
using namespace std;
int a[200005];
int main()
{
   // freopen("1372C.inp","r",stdin);
    int t,n,res=0;
    cin>>t;
    while (t--)
    {
        res=0;
        cin>>n;
        for (int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        for (int i=1;i<=n;++i)
        {
            if (a[i]==i&&(a[i-1]!=i-1))
            {
                res++;
            } 
        }
        cout<<res<<endl;
    }
    return 0;
}