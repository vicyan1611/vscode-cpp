#include <iostream>
using namespace std;
int a[100005],f[100004];
int main()
{ 
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=0;i<=k;++i)
    {
        bool ok=0;
        for (int j=1;j<=n;++j)
        {
            if (i>=a[j])
                if (f[i-a[j]]==0)
                {
                    ok=1;
                    break;
                }
        }
        f[i] = ok;
    }   
    if (f[k]==1) cout<<"First"; else cout<<"Second";
    return 0;
}