#include <iostream>
#include <string>
#include <fstream>
#define Nmax 1000005
using namespace std;
ifstream fi ("bramex.inp");
ofstream fo ("bramex.out");
int cnt=0,N,M,iscnt[Nmax],child[27][Nmax];
void add (string st)
{
    int x=0,node=0;
    for (char c:st)
    {
        x=c-'a';
        if (child[x][node]==0)
        {
            child[x][node]=++cnt;
        }
        node=child[x][node];
        iscnt[node]++;
    }
}
int look (string st)
{
    int x=0,node=0;
    for (char c:st)
    {
        x=c-'a';
        if (child[x][node]==0) return 0;
        node=child[x][node];
    }
    return iscnt[node];
}
int main()
{
    fi>>N;
    while (N--)
    {
        string st;
        fi>>st;
        add(st);
    }
    fi>>M;
    while (M--)
    {
        string st;
        fi>>st;
        fo<<look(st)<<endl;
    }
    return 0;
}