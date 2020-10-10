#include <iostream>
#include <fstream>
#define Nmax 300005
using namespace std;
ifstream fi ("divseq.inp");
ofstream fo ("divseq.out");
int a[Nmax],T[Nmax];
int main()
{
    int n;
    fi>>n;
    for (int i = 1; i <= n; i++)
    {
        fi>>a[i];
    }
    T[1]=0;
    int k=0;
    for (int i = 2; i <= n; ++i)
    {
        while (a[i]!=a[k+1] && k>0) k=T[k];
        if (a[i]==a[k+1])
        {
            k++;
        }
        T[i]=k;
    }
    int res=0;
    /*for (int i = 1; i <= n; i++)
    {
        if (T[i]+1 == T[i+1] && T[i] != 0)
        {
            fo<<i-1;
            return 0;
        }
    }*/
    res = n - T[n];
    fo<<res;
    return 0;
}