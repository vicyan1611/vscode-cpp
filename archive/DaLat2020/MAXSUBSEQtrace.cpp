#include <iostream>
#include <deque>
using namespace std;
int f1[1000004],n,L1,L2,a[1000004],res = -1e9,s1,s2;
deque <int> dq;
int main()
{
    cin>>n>>L1>>L2;

    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        f1[i]=a[i];
        a[i]+=a[i-1];
    }
    for (int i=L1;i<=n;++i)
    {
        int j=i-L1;
        while (!dq.empty()&&a[dq.back()]>a[j])
        {
            dq.pop_back();
        }
        dq.push_back(j);
        while (!dq.empty()&&i-dq.front()>L2)
        {
            dq.pop_front();
        }
        if (res<a[i]-a[dq.front()])
        {
            res=a[i]-a[dq.front()];
            s1=dq.front()+1;
            s2=i;
        }
    }
    cout<<res<<endl<<s1<<" "<<s2;
    return 0;
}