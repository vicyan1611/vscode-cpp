#include <iostream>
using namespace std;
int main()
{
    long long t;
    cin>>t;
    while (t--)
    {
        long long n,r;
        cin>>n>>r;
        if (r>=n)
        {
            cout<<n*(n-1)/2+1<<endl;
        } else
        {
            cout<<r*(r+1)/2<<endl;
        }
    }
    return 0;
}