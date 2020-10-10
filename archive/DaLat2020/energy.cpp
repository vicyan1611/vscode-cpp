#include <iostream>
#include <queue>
using namespace std;
pair <int,int> a[100005];
priority_queue<int> A,P;
int main()
{
    freopen("energy.inp","r",stdin);
    freopen("energy.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n*2;++i)
    {
        cin>>a[i].first>>a[i].second;
    }
    int res=0;
    for (int i=1;i<=2*n;++i)
    {
        if (a[i].first>=a[i].second)
        {
            res+=a[i].second;
            A.push(a[i].first-a[i].second);
        } else
        {
            res+=a[i].first;
            P.push(a[i].second-a[i].first);
        }
    }
    if (A.size()<=n)
    {
        while (!A.empty())
        {
            res+=A.top();
            A.pop();
        }
        int cnt=n;
        while (cnt>0)
        {
            res+=P.top();
            P.pop();
            cnt--;
        }
        
    } else
    {
        while (!P.empty())
        {
            res+=P.top();
            P.pop();
        }
        int cnt=n;
        while (cnt>0)
        {
            res+=A.top();
            A.pop();
            cnt--;
        }
    }
    cout<<res;
    return 0;
}