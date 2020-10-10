#include <iostream>
#include <fstream>
#include <deque>
using namespace std;
int a[3503];
deque <int> dq,q;
int main()
{
    freopen("1290A.inp","r",stdin);
  //  freopen("1290A.out","w",stdout);
    int t;
    cin>>t;
    while (t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        for (int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        k=min(k,m-1);
        int res=0;
        for (int i=0;i<=k;++i)
        {
            int tmp=(int)1e9+5;
            for (int j=0;j<=(m-1)-k;++j)
            {
                cout<<i<<" "<<j<<endl;
                tmp=min(tmp,max(a[i+j+1],a[i+j+1+n-m]));
            }
            res=max(res,tmp);
        }
        cout<<res<<endl;
    }
    return 0;
}