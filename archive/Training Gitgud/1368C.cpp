#include <iostream>
using namespace std;
int n;
int main()
{
    cin>>n;
    cout<<n*3+3+1<<endl;
    int x=0;
    int y=0;
    for (int i=1;i<=n+1;++i)
    {
        cout<<x<<" "<<y<<endl;
        cout<<x+1<<" "<<y<<endl;
        cout<<x<<" "<<y+1<<endl;
        x++;
        y++;
        if (i==n+1)
        {
            cout<<x<<" "<<y<<endl;
        }
    }
    return 0;
}