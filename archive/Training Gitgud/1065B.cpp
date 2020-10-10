#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    long long n,m,minn,maxx;
    cin>>n>>m;
    long long n2=m*2;
    if (n2>n) minn=0; else minn=n-n2;
    long long edge=0; 
    long long ver=0;
    for (long long i=2;i<=n*n;++i)
    {
        if (i*(i-1)/2<=m)
        {
            edge=i*(i-1)/2;
            ver=i;
        }  else break;
    }
    if (edge==m) maxx=n-ver; else
    {
        if (ver!=0) maxx=n-(ver+1); else maxx=n;
    }
    if (maxx<0) maxx=0;
    cout<<minn<<" "<<maxx;    
}