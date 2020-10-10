#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(x,a,b) for(int x=a; x<=b; x++)
int n,k;
pair<int,int> a[159357];
ll f[159357];
ll ans = 0;

int main()
{
    freopen("thidau.inp","r",stdin);
    freopen("thidau.ans","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    For(i,1,n) cin>>a[i].first;
    For(i,1,n) cin>>a[i].second;
    For(i,1,n)
    {
        f[i] = a[i].second;
        For(j,1,i-1)
            if (a[j].first + k <= a[i].first && f[i]<f[j]+a[i].second)
                f[i] = f[j]+a[i].second;
        ans=max(ans,f[i]);
    }
    //For(i,1,n) cout<<f[i]<<" ";
    cout<<ans;



}
    