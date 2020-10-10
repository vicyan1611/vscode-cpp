#include <iostream>
#include <fstream>
using namespace std;
int a[1000004],f2[100004],f1[1000004];
ifstream fi ("quality.inp");
ofstream fo ("quality.out");
int main()
{
    int n;
    fi>>n;
    for (int i=1;i<=n;++i)
    {
        fi>>a[i];
    }
    /*for (int i=1;i<=n;++i)
    {
        if (a[i]-f1[i-1]==1) f1[i]=a[i]; else f1[i]=f1[i-1];
    }
    for (int i = n;i>=1; --i)
    {
        if (a[i]-f2[i+1]==1) f2[i]=a[i]; else f2[i]=f2[i+1];
    }
    int res=0;
    for (int i=1;i<=n;++i)
    {
        if (f1[i]==f2[i]) res=max(res,a[i]);
    }*/
    int res=1;
    int i=1;
    int j=n;
    while (i<=j)
    {
        while (i<=j)
        {
            if (a[i]==res) break; else i++;
        }
        while (i<=j)
        {
            if (a[j]==res) break; else j--;
        }
        if (a[i]==res&&a[j]==res)
        {
            res++;
            i++;
            j--;
        }
    }
    fo<<res--;
    return 0;
}