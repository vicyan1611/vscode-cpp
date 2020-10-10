#include <iostream>
#include <fstream>
using namespace std;
int n,k,q,cnt[200003],f[200003];
int main()
{
  //  freopen("816B.inp","r",stdin);
   // freopen("816B.out","w",stdout);
    cin>>n>>k>>q;
    for (int i=1;i<=n;++i)
    {
        int l,r;
        cin>>l>>r;
        cnt[l]++;
        cnt[r+1]--;
    }
    for (int i=1;i<=200001;++i)
    {
        cnt[i]=cnt[i-1]+cnt[i];
    }
    for (int i=1;i<=200001;++i)
    {
        if (cnt[i]>=k) f[i]=f[i-1]+1; else f[i]=f[i-1];
    }
    while (q--)
    {
        int l,r;
        cin>>l>>r;
        int res=f[r]-f[l];
        if (cnt[l]>=k) res+=1;
        cout<<res<<endl;
    }
    return 0;
}