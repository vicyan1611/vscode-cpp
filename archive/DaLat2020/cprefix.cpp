#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream fi ("cprefix.inp");
ofstream fo ("cprefix.out");
int z[100004],f[100004];
string st;
int main()
{
    fi>>st;
    int n=st.size();
    int x=0,l=-1,r=-1;
    for (int i=0;i<n;++i)
    {
        if (i>r) x=0; else x=min(z[i-l],r-i);
        while (st[x]==st[i+x]&&i+x<n) x++;
        z[i]=x;
        if (i+x>=r)
        {
            l=i;
            r=i+x;
        }
        f[x]++;
    }
    for (int i=100002;i>=0;--i)
        f[i]+=f[i+1];
    for (int i=1;i<=n;++i)
    {
        fo<<f[i]<<" ";
    }
    return 0;
}