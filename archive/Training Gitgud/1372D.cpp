#include <iostream>
using namespace std;
int a[200005];
int main()
{
    //thay in = long long
    int n;
    cin>>n;
    for (long long i=1;i<=n;++i)
        cin>>a[i];
    long long tong1=0;
    long long tong2=0;
    for (long long i=1;i<=n;i+=2)
    {
        tong1+=a[i];
    }
    for (long long i=2;i<=n;i+=2)
    {
        tong2+=a[i];
    }
    cout<<max(tong1,tong2);
    return 0;

}