#include <iostream>
#include <fstream>
#include <string>
#define Nmax 500005
using namespace std;
ifstream fi ("foundstr.inp");
ofstream fo ("foundstr.out");
int N,M,child[27][Nmax],cnt;
bool isEnd[Nmax];
void add(string st)
{
    int node=0,x=0;
    for (char c:st)
    {
        x=c-'a';
        if (child[x][node]==0) child[x][node]=++cnt; 
        node=child[x][node];
    }
    isEnd[node]=1;
}
bool look(string st)
{
    int node=0,x=0;
    for (char c:st)
    {
        x=c-'a';
        if (child[x][node]==0) return 0;
        node=child[x][node];
    }
    return isEnd[node];
}
int main()
{
    cnt=0;
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