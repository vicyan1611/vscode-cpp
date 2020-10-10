//https://codeforces.com/problemset/problem/1070/F
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int a[400005],b[400005],d[400005],c[400005];
int main()
{
    freopen("1070F.inp","r",stdin);
    int n;
    int cnt_a=0;
    int cnt_b=0;
    int cnt_c=0;
    int cnt_d=0;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        char char1,char2;
        int influ;
        cin>>char1>>char2>>influ;
        if (char1=='1'&&char2=='0') a[++cnt_a]=influ;
        else if (char1=='0'&&char2=='1') b[++cnt_b]=influ; else if (char1=='1'&&char2=='1') c[++cnt_c]=influ; else d[++cnt_d]=influ;
    }
    cout<<cnt_a<<" "<<cnt_b<<" "<<cnt_c;
    sort(1+a,1+a+cnt_a,greater<int>());
    sort(1+b,1+b+cnt_b,greater <int> ());
    sort(1+c,1+c+cnt_c,greater<int> ());
     sort(1+d,1+d+cnt_d,greater<int> ());
    int res=0;
    for (int i=1;i<=min(cnt_a,cnt_b);++i)
    {
        res+=a[i]+b[i];
    }
    for (int i=1;i<=cnt_c;++i)
    {
        if (i<=cnt_d) res+=c[i]+d[i]; else
        {
            res+=c[i];
        }
    }
    cout<<res;
    return 0;
}