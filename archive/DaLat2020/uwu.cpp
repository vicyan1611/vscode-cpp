#include <iostream>
#include <cstdio>
#define M 100005
#define oo 2e9
using namespace std;
int n;
int a[M];
int b[M];
int f[M];
int res[M], m;
int chat(int t, int l, int r){
    int i = l, j = r, mid, k;
    while(i <= j){
        mid = (i + j) / 2;
        if(b[mid] >= t){
            k = mid;
            j = mid - 1;
        }
        else 
            i = mid + 1;
    }
    return k;
}
int main(){
    cin>>n;
    for(int i = 1; i <= n; ++i)
        b[i] = oo;
    for(int i = 1; i <= n; ++i)
        cin>>a[i];
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        int ta = chat(a[i], 1, n);
        b[ta] = a[i];
        f[i] = ta;
        ans = max(ans, ta);
    }
    cout<<ans<<endl;
    int cnt=ans;
    for (int i=n;i>=1;--i)
    {
        if (f[i]==cnt)
        {
            res[cnt]=i;
            cnt--;
        } 
    }
    for (int i=1;i<=ans;++i)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}