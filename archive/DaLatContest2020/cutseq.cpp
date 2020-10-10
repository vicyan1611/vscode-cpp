#include <iostream>
using namespace std;
int a[100005],sums[10005];
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        sums[i]=sums[i-1]+sums[i];
    }
    cin>>q;
    while (q--)
    {
        int c;
        cin>>c;
        for (int i=1;i<=n;++i)
        {
        }
    }
    return 0;
}