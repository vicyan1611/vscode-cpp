//Vinh copy code nhi quoc gia, dung chui Vinh hu hu :(
#include <iostream>
using namespace std;
long long sums[405],n,a[405],f[405][405];
long long trau(int i,int j)
{
    if (i == j) return 0;
    long long &res = f[i][j];
    if (res!=-1) return res;
    res=1e18;
    for (int mid = i; mid < j; ++mid)
    {
        res=min(res,trau(i,mid)+trau(mid+1,j));
    }
    res+=(sums[j]-sums[i-1]);
    return res;
}
int main()
{
    cin>>n;
    for (long long i = 1; i <= n; i++)
    {
        cin>>a[i];
        sums[i]=sums[i-1] + a[i];
    }
    for (long long i = 0; i <= n;++i)
    {
        for (long long j = 0; j <= n; ++j)
            f[i][j]=-1;
    }
    long long res=1e8;
    for (int length = 2; length <= n; ++length)
    {
        for (int i = 1; i <= n; i++)
        {
            int j=i+length-1;
            if (j>n) break;
            res=trau(i,j);
        }
    }
    cout<<trau(1,n)<<endl;
    return 0;
}