#include <iostream>
using namespace std;
bool checkle(int n)
{
    int res=0;
    while (n!=0)
    {
        res+=n%10;
        n/=10;
    }
    return (res&1);
}
int main()
{
    int a,b;
    cin>>a>>b;
    a--;
    int fa=(a+1+checkle(a))/2;
    int fb=(b+1+checkle(b))/2;
    cout<<fb-fa;
    return 0;
}