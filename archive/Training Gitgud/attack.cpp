#include <iostream>
#include <fstream>
#define endl '\n'
#define ll long long
using namespace std;
ll n,k,a[100005],b[100005];
bool checkk(ll x)
{
    ll tongcong=0;
    for (int i=1;i<=n;++i)
    {
        if (a[i]>x) continue;
        tongcong+=((x-a[i])/b[i])+1;
        if (tongcong>k) return true;
    }
    return false;
}
ll bnrs()
{
    ll l=1,r=2e18,e;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (checkk(mid))
        {
            e=mid;
            r=mid-1;
        } else l=mid+1;
    }
    return e;
}
int main()
{
    freopen("attack.inp","r",stdin);
    freopen("attack.out","w",stdout);
    cin>>n>>k;
    for (ll i=1;i<=n;++i)
    {
        cin>>a[i]>>b[i];
    }
    cout<<bnrs();
    return 0;
}