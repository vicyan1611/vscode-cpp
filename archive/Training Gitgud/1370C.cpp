#include <iostream>
#include <math.h>
using namespace std;
bool checkprime(int n)
{
    if (n==0||n==1) return false;
    for (int i=2;i*i<=n;++i)
    {
        if (n%i==0)
        {
            return false;
        }
        
    }
    return true;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        bool lose=0;
        if (n==1) lose=1;
        if (n>2&&n%2==0)
        {
            if ((n&(n-1))==false)
            {
                lose=1;
            } else
            if (n%4!=0&&checkprime(n/2))
            {
                lose=1;
            } 
        }
        if (lose==0) cout<<"Ashishgup"<<endl; else cout<<"FastestFinger"<<endl;
    }
    return 0;
}