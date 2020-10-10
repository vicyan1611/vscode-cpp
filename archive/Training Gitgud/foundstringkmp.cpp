#include <iostream>
#include <string>
using namespace std;
string st1,st2;
int T[100004];
int main()
{
    cin>>st1>>st2;
    int n=st1.size()+st2.size();
    st2=" "+st1+st2;
    T[1]=0;
    int k=0;
    for (int i = 2; i <= n; i++)
    {
        while (st2[i]!=st2[k+i]&&k>0) k=T[k];
        if (st2[i]==st2[k+1]) k++;
        T[i]=k;
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<T[i]<<" ";
    }
    
    return 0;
}