#include <iostream>
using namespace std;
int n,l[1004],r[1004],a[1004];
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>l[i];
    for (int i=1;i<=n;++i)
        cin>>r[i];
    for (int i=1;i<=n;++i)
        a[i]=n-l[i]-r[i];
    for (int i=1;i<n;++i)
    {
        for (int j=i+1;j<=n;++j)
        {
            r[i]-=(a[j]>a[i]);
        }
    }
    for (int i=2;i<=n;++i)
    {
        for (int j=1;j<i;++j)
        {
            l[i]-= (a[j]>a[i]);
        }
    }
    for (int i=1;i<=n;++i)
    {
        if (r[i]!=0||l[i]!=0)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
    return 0;
}