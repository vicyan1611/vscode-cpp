#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<min(a*4,min(2*b+1,4*c+2));
    return 0;
}