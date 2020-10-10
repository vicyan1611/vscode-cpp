#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int z[100005],cnt[100005];
string st;
int n,cnt_res;
vector <pair <int,int>> res;
void zfunction()
{
    int L=1,R=1;
    z[1]=n;
    for (int i=2;i<=n;i++)
    {
        if (i>R)
        {
            L=i;
            R=i;
            while (R<=n&&st[R]==st[R-L]) R++;
            z[i]=R-L;
            R--;
        } else
        {
            int k=i-L;
            if (z[k]<R-i+1) z[i]=z[k]; else
            {
                L=i;
                while (R<=n&&st[R]==st[R-L]) R++;
                z[i]=R-L;
                R--; 
            }
        }
        
    }
}
int main()
{
    cin>>st;
    n=st.size();
    st=" "+st;
    zfunction();
    for (int i=1;i<=n;++i)
    {
        cnt[2]++;
        cnt[z[i]]--;
    }
    for (int i=1;i<=n;++i)
    {
        cnt[i]+=cnt[i-1];
    }
    for (int i=1;i<=n;++i)
    {
        if (z[n-i]==i)
        {
            cnt_res++;
            res.push_back({i,cnt[i]});
        }
           
    }
    cout<<cnt_res<<endl;
    sort(res.begin(),res.end());
    for (auto v:res)
    {
        cout<<v.first<<" "<<v.second<<endl;
    }
    return 0;
}