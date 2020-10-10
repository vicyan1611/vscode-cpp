#include <fstream>
#include <iostream>
#include <string>
using namespace std;
ifstream fi ("excess.inp");
ofstream fo ("excess.out");
string st;
int main()
{
    fi>>st;
    //cin>>st;
    int n=st.size();
    st=" "+st;
    int p=1,q=n;
    while (p<q&&st[p]==st[q]) ++p,--q;
    int i=p+1,j=q;
    int res=-1;
    while (i<=j&&st[i]==st[j]) i++,j--;
    if (i>j) res=p; else
    {
        i=p;j=q-1;
        while (i<=j&&st[i]==st[j]) i++,j--;
        if (i>j) res=q; else
        {
            return cout<<0,0;
        }
    }
    cout<<res;
    return 0;
}