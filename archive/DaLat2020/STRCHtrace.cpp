#include <iostream>
#include <string>
using namespace std;
string sta,stb;
int f[1003][1003];
int trau(int sizea,int sizeb)
{
    if (sizea==0)
        return f[sizea][sizeb]=sizeb;
    if (sizeb==0)
        return f[sizea][sizeb]=sizea;
    int &res=f[sizea][sizeb];
    if (res!=-1) return res;
    res=1e9;
    if (sta[sizea-1]==stb[sizeb-1])
    {
        res=trau(sizea-1,sizeb-1);
    } else
    {
        int rep=trau(sizea-1,sizeb-1)+1;
        int del=trau(sizea-1,sizeb)+1;
        int ins=trau(sizea,sizeb-1)+1;
        res=min(rep,min(del,ins));
    }
    return res;
}
void trace(int sizea,int sizeb)
{
    if (sizea==0)
    {
        for (int i=0;i<sizeb;++i)
        {
            cout<<"INSERT"<<" "<<i+1<<" "<<stb[i]<<'\n';
        }
        return;
    }
    if (sizeb==0)
    {
        for (int i=0;i<sizea;++i)
        {
            cout<<"DELETE"<<" "<<i+1<<'\n';
        }
        return;
    }
    if (sta[sizea-1]==stb[sizeb-1])
    {
        trace(sizea-1,sizeb-1);
        return;
    }
    int i=sizea;
    int j=sizeb;
    int rep=f[i-1][j-1]+1;
    int del=f[i-1][j]+1;
    int ins=f[i][j-1]+1;
    int res=f[i][j];
    if (res==rep)
    {
        cout<<"REPLACE"<<" "<<i<<" "<<stb[j-1]<<endl;
        trace(i-1,j-1);
        return;
    } else if (res==ins)
    {
        cout<<"INSERT"<<" "<<i<<" "<<stb[j-1]<<endl;
        trace(i,j-1);
        return;
    } else if (res==del)
    {
        cout<<"DELETE"<<" "<<i<<endl;
        trace(i-1,j);
        return;
    }

}
int main()
{
    for (int i=0;i<=1002;++i)
        for (int j=0;j<=1002;++j)
            f[i][j]=-1;
    cin>>sta>>stb;
    cout<<trau(sta.size(),stb.size())<<'\n';
    trace(sta.size(),stb.size());
    return 0;
}