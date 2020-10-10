#include <iostream>
#include <fstream>
#define endl '\n'
using namespace std;
long long N,bit,cnt[1000005],minPrime[1000005];
void etho()
{
    minPrime[1]=1;
    minPrime[0]=1;
    for (long long i=2;i*i<=1000005;++i)
    {
        if (minPrime[i]==0)
        {
            long long j=i+i;
            while (j<=1000005)
            {
                minPrime[j]=i;
                j+=i;
            }
        }
    }
    for (long long i=2;i<=1000005;++i)
    {
        if (minPrime[i]==0) minPrime[i]=i;
    }
}
bool checkk(long long x)
{
    while (x>1)
    {
        cnt[minPrime[x]]++;
        if (cnt[minPrime[x]]%2==0) bit--; else bit++;
        x/=minPrime[x];
    }
    return (bit==0);
}
int main()
{
    freopen("SQNUM.inp","r",stdin);
    freopen("SQNUM.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    etho();
    bit=0;
    cin>>N;
    while (N--)
    {
        long long x;
        cin>>x;
        if (checkk(x)) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }
    return 0;
}