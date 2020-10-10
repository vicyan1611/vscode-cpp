#include <iostream>
#include <fstream>
using namespace std;
ifstream fi ("sandstorm.inp");
ofstream fo ("sandstorm.out");
int main()
{
    long long a,b;
    fi>>a>>b;
    long long tmp=b-a;
    long long h=tmp*(tmp+1)/2;
    fo<<b-h<<endl;

}