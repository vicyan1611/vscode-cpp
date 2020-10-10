#include <iostream>
using namespace std;
int main()
{
    int a,n,b;
    cin>>a>>n;
    b=a+n;
    if (a>0&&b<=0) b--; else if (a<0&&b>=0) b++;
    cout<<b;
    return 0;
}