#include <iostream>
#include <algorithm>
#define Nmax 200005
using namespace std;
long long n, b[Nmax], res;
pair <long long,long long> a[Nmax], f[Nmax];
long long bnrs (long long ta)
{
    long long l = 1, r = n, k = -1;
    while (l <= r)
    {
        long long mid=(l + r) / 2;
        if (b[mid] >= ta)
        {
            k = mid;
            r = mid-1;
        } else l = mid+1;
    }
    return k;
}
bool cmp (pair <long long, long long> a, pair <long long, long long> b)
{
    if (a.second != b.second)
    {
        return a.second < b.second;
    } else
    {
        return a.first > b.first;
    }
}
void cal()
{
    long long res=0;
    sort(1 + f, 1 + f + n, cmp);
    for (long long i = 1; i <= n; i++)
    {
        if (f[i].second != f[i-1].second)
        {
            res += f[i].first;
        }
        cout<<f[i].first<<" ";
    }
    cout << res;
}
int main()
{
    cin>>n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i].first;
    }
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i].second;
    }
    for (long long i = 1; i <= n; i++)
    {
        b[i] = 1e9;
    }
    for (long long i = 1; i <= n; ++i)
    {
        long long vt = bnrs(a[i].first);
        f[i].first = a[i].second;
        f[i].second = vt;
        b[vt] = a[i].first;
    }
    cal();
    return 0;
}