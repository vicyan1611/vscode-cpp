#include <iostream>
#include <fstream>
using namespace std;
int main()
{
   // freopen("1371C.inp","r",stdin);
    long long t;
    cin>>t;
    while (t--)
    {
        long long a,b,n,m;
        cin>>a>>b>>n>>m;
        if (m>min(a,b)||(a+b<n+m)) cout<<"NO"<<endl; else cout<<"YES"<<endl;
    }
    return 0;
}