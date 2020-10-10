#include <iostream>
#include <vector>
using namespace std;
int n;
vector <int> f[1003];
bool vis[1003];
int res[1003],cnt;
void toposort(int i)
{
    vis[i]=true;
    for (int v:f[i])
    {
        if (!vis[v])
        {
            toposort(v);
        }
    }
    res[cnt]=i;
    cnt--;
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=n;++j)
        {
            char ch;
            cin>>ch;
            if (ch=='1')
            {   
                f[i].push_back(j);
            }
        }
    }
    cnt=n;
    for (int i=1;i<=n;++i)
    {
        if (!vis[i])
        {
            toposort(i);
        }
    }
    for (int i=1;i<=n;++i) cout<<res[i]<<" ";
    return 0;
}