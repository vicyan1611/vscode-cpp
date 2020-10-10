#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string st;
int n,f[105];
int bnr(int x)
{
    int l=1,r=n;
    int k=105;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (f[mid]==x)
        {
            k=mid;
            return k;
        } else if (f[mid]>x) r=mid-1; else l=mid+1;
    }
    return -1;
}
int main()
{
   // freopen("1030C.inp","r",stdin);
    //freopen("1030C.out","w",stdout);
    cin>>n>>st;
    st=" "+st;
    for (int i=1;i<=n;++i)
    {
        f[i]=f[i-1]+(st[i]-48);
        //cout<<f[i]<<" ";
    }
    for (int i=2;i<=f[n];++i)
    {
        if (f[n]%i==0)
        {
            bool check=true;
            int x=f[n]/i;
            int t=x;
            int pos;
            while (x<=f[n])
            {
                pos=bnr(x);
                if (pos!=-1) x+=t; else
                {
                    check=false;
                    break;
                } 
            } 
            if (check==true)
            {
                cout<<"YES";
                return 0;
            }
        }
    }
    int d=0;
    for (int i=1;i<=n;++i)
    {
        if (st[i]=='0') d++;
    }
    if (d==n) cout<<"YES";else cout<<"NO";
    return 0;
}