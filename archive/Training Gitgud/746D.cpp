#include <iostream>
using namespace std;
char A='G',B='B';
int main()
{
    int n,k,a,b;
    cin>>n>>k>>a>>b;
    if(a<b)swap(a,b),swap(A,B);
    
    return 0;
} 