#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string st1,st2;
int res[2000004],z[2000006];
int main()
{
   // freopen("foundstring.inp","r",stdin);
   // freopen("foundstring.out","w",stdout);
    cin>>st2>>st1;
    st1=st2+st1;
    int n=st1.size();
    z[0]=0;
    int x=0;
    int l=-1,r=-1;
    for (int i=0;i<n;++i)
    {
        if (i>r) x=0; else x=min(z[i-l],r-i);
        while (st1[x]==st1[i+x]&&i+x<n) x++;
        z[i]=x;
        if (i+x>=r)
        {
            l=i;
            r=i+z[i];
        }
        cout<<z[i]<<" ";
    }
    cout<<endl;
    int cnt=0;
    for (int i=st2.size();i<n;++i)
    {
        if (z[i]>=st2.size())
        {
            res[++cnt]=i-st2.size()+1;
        }
    }
    cout<<cnt<<endl;
    for (int i=1;i<=cnt;++i)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}