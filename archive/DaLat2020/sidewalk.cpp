#include <iostream>
#include <fstream>
using namespace std;
ifstream fi ("sidewalk.inp");
ofstream fo ("sidewalk.out");
int main()
{
    int n,m,brick;
    fi>>n>>m>>brick;
    int res=0;
    while (true)
    {
        if (m==0||n==0) break;
        int brickneed=(n*2)+(m-2)*2;
        if (brick>=brickneed) 
        {
            brick-=brickneed;
            res++;
            n-=2;
            m-=2;
        } else break;
    }
    fo<<res;
    return 0;
}