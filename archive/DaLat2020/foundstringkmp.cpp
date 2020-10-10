#include <iostream>
#include <string>
#include <fstream>
using namespace std;
ifstream fi ("foundstring.inp");
ofstream fo ("foundstring.out");
string st1,st2;
int T[2000004],res[2000004];
int main()
{
    fi>>st1>>st2;
    int n=st1.size()+st2.size()+1;
    st2=" "+st1+" "+st2;
    T[1]=0;
    int k=0;
    for (int i = 2; i <= n; i++)
    {
        while (st2[i]!=st2[k+1]&&k>0) k=T[k];
        if (st2[i]==st2[k+1]) k++;
        T[i]=k;
    }
    int cnt=0;
    for (int i = st1.size()+1; i <= n; i++)
    {
        if (T[i]==st1.size())
        {
            res[++cnt]= i - (st1.size()*2);
        }
    }
    fo<<cnt<<endl;
    for (int i = 1; i <= cnt; i++)
    {
        fo<<res[i]<<" ";
    }
    return 0;
}