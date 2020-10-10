#include <iostream>
using namespace std;
int n,a[1000005];
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    sort(1+a,1+a+n);
    return 0;
}