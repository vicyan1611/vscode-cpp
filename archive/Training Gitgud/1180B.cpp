//https://codeforces.com/contest/1180/problem/B
#include <iostream>
#define endl '\n'
using namespace std;
int a[100005];
int main()
{
    int n;
    cin>>n;
    int negative_cnt=0;
    int positive_cnt=0;
    int cnt_0=0;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    int min_v=-1;
    int pos_min=-1;
    if (n%2==0)
    {
        for (int i=1;i<=n;++i) 
            if (a[i]>=0) a[i]=-a[i]-1;
    } else
    {
        for (int i=1;i<=n;++i)
        {
            if (a[i]>=0) a[i]=-a[i]-1;
            if (abs(a[i])>min_v)
            {
                min_v=abs(a[i]);
                pos_min=i;
            }
        }
        a[pos_min]=-a[pos_min]-1;
    }

    for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
    return 0;
}