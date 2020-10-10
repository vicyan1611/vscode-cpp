#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int n,S,a[1000004];
int main()
{
    freopen("SKYTRAM.inp","r",stdin);
      freopen("SKYTRAM.out","w",stdout);
    cin>>n>>S;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    sort(1+a,1+a+n);
    int i=1;
    int j=n;
    int res=0;
    while (i<=j)
    {
        if (i!=j)
        {
            if (a[i]+a[j]<=S)
            {
                res++;
                i++;
                j--;
            } else 
            {
                res++;
                j--;
            }
        } else
        {
            res++;
            i++;
            j--;
        }
        
    }   
    cout<<res;
    return 0;
}