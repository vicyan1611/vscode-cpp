#include <iostream>
#include <fstream>
using namespace std;

ifstream fi ("divseq.inp");
ofstream fo ("divseq.out");
int n,a[300005],z[300005];
int main()
{
    fi>>n;
    for (int i=0;i<n;++i)
    {
        fi>>a[i];
    }
    int x=0,l=-1,r=-1;
    for (int i=0;i<n;++i)
    {
        if (i>r) x=0; else x=min(z[i-l],r-i);
        while (a[x]==a[x+i]&&i+x<n) x++;
        z[i]=x;
        if (i+x>=r)
        {
            l=i;
            r=x+i;
        }
    }
    int res=0;
    for (int i=1;i<n;++i)
    {
        if (z[i]==n-i)
        {
            res=i;
            break;
        }
    }
    fo<<res;
    return 0;
}