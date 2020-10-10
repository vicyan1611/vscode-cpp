#include <iostream>
#include <fstream>
#include <map>
#define endl '\n'
using namespace std;
int n,m;
map <int,int> cnt;
int main()
{
    freopen("found2.inp","r",stdin);
    freopen("found2.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        cnt[x]++;
    }
    while (m--)
    {
        int x;
        cin>>x;
        cout<<cnt[x]<<endl;
    }
    return 0;
}