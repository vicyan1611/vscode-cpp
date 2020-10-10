#include <iostream>
#include <stack>
#include <fstream>
#define endl '\n'
#define ll long long
using namespace std;
long long a[100005],b[100005],n,m,h[100005];
stack <pair <long long,long long>> stack1,stack2;
pair <long long,long long> save_res[100005],res[100005];
long long cnt_save_res,cnt_res;
bool checkk(long long x)
{
    stack1=stack2;
    cnt_save_res=0;
    for (int i=1;i<=n;++i)
        a[i]=h[i];
    for (long long i=1;i<=n;++i)
    {
        if (a[i]>=x) continue;
        while (!stack1.empty()&&stack1.top().second+a[i]<x) stack1.pop();
        if (!stack1.empty())
        {
            ++cnt_save_res;
            save_res[cnt_save_res].first=i;
            save_res[cnt_save_res].second=stack1.top().first;
            a[i]+=stack1.top().second;
            stack1.pop();
        }
    }
    for (long long i=1;i<=n;++i)
    {
        if (a[i]<x) return false;
    }
    cnt_res=cnt_save_res;
    for (long long i=1;i<=cnt_save_res;++i)
    {
        res[i]=save_res[i];
    }
    return true;
}

long long bnrs()
{
    long long l=1,r=2e18,e=-1;
    while (l<=r)
    {
        long long mid=(l+r)/2;
        if (checkk(mid))
        {
            e=mid;
            l=mid+1;
        } else r=mid-1;
    }
    return e;
}
int main()
{
    freopen("wall.inp","r",stdin);
    freopen("wall.out","w",stdout);
    cin>>n;
    for (long long i=1;i<=n;++i)
    {
        cin>>h[i];
    }
    cin>>m;
    for (long long i=1;i<=m;++i)
    {
        cin>>b[i];
    }
    for (long long i=m;i>=1;--i)
    {
        stack2.push({i,b[i]});
    }
    cout<<bnrs()<<" "<<cnt_res<<endl;
    for (int i=1;i<=cnt_res;++i)
    {
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }
    return 0;
}