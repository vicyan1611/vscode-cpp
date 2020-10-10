#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#define endl '\n'
using namespace std;
long long n,q,a[1000005],L[1000005],cnt,R[1000005],f[1000005];
pair <long long,long long> cal[1000005];
stack <long long> stack1,stack2;
long long bnrsr(long long x)
{
    long long l=1,r=cnt,e=-1;
    while (l<=r)
    {
        long long mid=(l+r)/2;
        if (cal[mid].first==x) return mid; else
        if (cal[mid].first<x)
        {
            e=mid;
            l=mid+1;
        } else r=mid-1;
    }
    return e;
}
long long bnrsl(long long x)
{
    long long l=1,r=cnt,e=-1;
    while (l<=r)
    {
        long long mid=(l+r)/2;
        if (cal[mid].first==x) return mid; else
        if (cal[mid].first>x)
        {
            e=mid;
            r=mid-1;
        } else l=mid+1;
    }
    return e;
}
int main()
{
    freopen("CNTSEQ.inp","r",stdin);
    freopen("CNTSEQ.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (long long i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for (long long i=1;i<=n;++i)
    {
        while (!stack1.empty()&&a[stack1.top()]<=a[i])
        {
            stack1.pop();
        }
        if (!stack1.empty()) L[i]=stack1.top(); else L[i]=0;
        stack1.push(i);
    }
    stack1=stack2;
    for (long long i=n;i>=1;i--)
    {
        while (!stack1.empty()&&a[stack1.top()]<a[i])
        {
            stack1.pop();
        }
        if (!stack1.empty()) R[i]=stack1.top(); else R[i]=n+1;
        stack1.push(i);
    }
    for (long long i=1;i<=n;++i)
    {
        cal[i].second=(R[i]-i)*(i-L[i]);
        cal[i].first=a[i];
    }
    sort(1+cal,1+cal+n);
    cnt=1;
    for (long long i=2;i<=n;++i)
    {
        if (cal[i].first==cal[cnt].first)
        {
            cal[cnt].second+=cal[i].second;
        } else
        {
            cal[++cnt].first=cal[i].first;
            cal[cnt].second=cal[i].second;
        }
    }
    for (long long i=1;i<=cnt;++i)
    {
        f[i]=f[i-1]+cal[i].second;
    }
    cin>>q;
    while (q--)
    {
        long long l,r;
        cin>>l>>r;
        l=bnrsl(l);
        r=bnrsr(r);
        if (l!=-1&&r!=-1) cout<<f[r]-f[l]+cal[l].second<<endl; else cout<<"0"<<endl;
    }
    return 0;
}