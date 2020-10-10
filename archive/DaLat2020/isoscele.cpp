#include <iostream>
#include <fstream>
using namespace std;

    ifstream fi ("isoscele.inp");
    ofstream fo ("isoscele.out");
int main()
{
    long long n;
    fi>>n;
    long long res=n*((n-1)/2);
    if (n%3==0)
    {
        res-=2*n/3;
    }
    cout<<res;
    return 0;
}