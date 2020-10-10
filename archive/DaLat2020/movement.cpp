#include <iostream>
using namespace std;
int main()
{
    cin>>a>>b>>n;
    int movement=b-a;
    if (n%a==0)
    {
        buocdi=n/movement; else buocdi=n/movement+1;
    }
    cout<<buocdi*2-1;
    //cong thuc cua thay 1+2*((b-b+(b-a)-1)/(b-a))
    return 0;
}