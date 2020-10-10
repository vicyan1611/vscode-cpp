#include <iostream>
using namespace std;
int n,m,f1[504],f2[504],f3[504][2],f4[504];
int trau1(int i)
{
    if (i>m+1) return 0;
    if (i==m+1) return 1;
    int &res=f1[i];
    if (res!=-1) return res;
    res=0;
    res+=trau1(i+1);
    res+=trau1(i+2);
    res+=trau1(i+3);
    return res;
}
int trau2(int i)
{
    if (i>n+1) return 0;
    if (i==n+1) return 1;
    int &res=f2[i];
    if (res!=-1) return res;
    res=0;
    res+=trau2(i+1);
    res+=trau2(i+2);
    res+=trau2(i+3);
    return res;
}
int trau3(int i,bool nhay3)
{
    if (i>n+1) return 0;
    if (i==n+1) return 1;
    int &res=f3[i][nhay3];
    if (res!=-1) return res;
    res=0;
    if (nhay3==false)
    {
        res+=trau3(i+1,1);
        res+=trau3(i+1,0);
        res+=trau3(i+2,1);
        res+=trau3(i+2,0);
    } else
    {
        res+=trau3(i+1,1);
        res+=trau3(i+2,1);
    }
    return res;
}
int trau4(int i)
{
    if (i>m+1) return 0;
    if (i==m+1) return 1;
    int &res=f4[i];
    if (res!=-1) return res;
    res=0;
    res+=trau1(i+1);
    res+=trau1(i+2);
    return res;
}
int main()
{
    for (int i=0;i<=503;++i)
    {
        f1[i]=-1;
        f2[i]=-1;
        f4[i]=-1;
        f3[i][0]=-1;
        f3[i][1]=-1;
    }
    cin>>m>>n;
    cout<<trau1(1)<<" "<<trau2(1)<<" "<<trau3(1,0)<<" "<<trau4(1)<<" "<<trau1(1)*trau2(1)*trau3(1,0)*trau4(1);
    return 0;
}