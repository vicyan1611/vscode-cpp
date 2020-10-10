#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string st1,st2;
int n,m,f[3004][3004];
string res;
void truyvet()
{
    if (m*n==0) return;
    if (st1[n]==st2[m])
    {
        res=st1[n]+res;
        n--;
        m--;
    } else if (f[n-1][m]==f[n][m]) n--; else m--;
    truyvet();
}
int main()
{
    cin>>st1>>st2;
    n=st1.size();
    m=st2.size();
    st1=" "+st1;
    st2=" "+st2;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
        {
            if (st1[i]==st2[j])
            {
                f[i][j]=f[i-1][j-1]+1;
            } else f[i][j]=max(f[i-1][j],f[i][j-1]);
        }
    res="";
    truyvet();
    cout<<res;
    return 0;
}