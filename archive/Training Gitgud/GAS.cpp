#include <iostream>
#include <fstream>
#include <deque>
using namespace std;
deque <long long> dq;
long long c[1000005],res,k;
int main()
{
    freopen("gas.inp","r",stdin);
    freopen("gas.out","w",stdout);
    long long n;
    cin>>n>>k;
    for (long long i=0;i<n;++i)
    {
        cin>>c[i];
    }
    dq.push_back(0);
    for (long long i=1;i<=n;++i)
    {
        if (dq.front()+k<i)
            dq.pop_front();
        res+=c[dq.front()];
        if(i == n)
            break;
        while (!dq.empty()&&c[dq.back()]>=c[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<<res;
    return 0;
}