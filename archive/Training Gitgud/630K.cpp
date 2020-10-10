#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long n2=n/2;
    long long n3=n/3;
    long long n5=n/5;
    long long n7=n/7;
    long long res=n2+n3+n5+n7;
    long long n23=n/(2*3);
    long long n25=n/(2*5);
    long long n27=n/(2*7);
    long long n35=n/(3*5);
    long long n37=n/(3*7);
    long long n57=n/(5*7);
    long long n235=n/(2*3*5);
    long long n237=n/(2*3*7);
    long long n257=n/(2*5*7);
    long long n357=n/(3*5*7);
    long long n2357=n/(3*5*2*7);
    res=res-(n23+n25+n27+n35+n37+n57);
    res+=(n235+n237+n257+n357);
    res-=n2357;
    cout<<n-res;
    return 0;
} 