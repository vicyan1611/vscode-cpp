#include <iostream>
#include <fstream>
using namespace std;
int  a[1004],max1,max2,res;
pair <int,int> pos1,pos2;
int main()
{
    freopen("express.inp","r",stdin);
    freopen("express.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<n;++i)
    {
        if (a[i]*a[i+1]>max1)
        {
            max1=a[i]*a[i+1];
            pos1.first=i;
            pos1.second=i+1;
        } else if (a[i]*a[i+1]==max1)
        {
            if (abs(a[i]-a[i+1])<abs(a[pos1.first]-a[pos1.second]))
            {
                pos1.first=i;
                pos1.second=i+1;
            }
        }
    }
    for (int i=1;i<n;++i)
    {
        if (a[i]*a[i+1]>=max2)
        {
            if (i!=pos1.first||a[i]*a[i+1]!=max1)
            {
                if (a[i]*a[i+1]>max2)
                {
                    max2=a[i]*a[i+1];
                    pos2.first=i;
                    pos2.second=i+1;
                } else 
                {
                    if (abs(a[i]-a[i+1])<abs(a[pos2.first]-a[pos2.second]))
                    {
                        pos2.first=i;
                        pos2.second=i+1;
                    }
                }
            }
        }
    }
    //cout<<pos1.first<<" "<<pos1.second<<endl<<pos2.first<<" "<<pos2.second;
    res=0;
    for (int i=1;i<=n;++i)
    {
        if (i!=pos1.first&&i!=pos1.second&&i!=pos2.first&&i!=pos2.second)
        {
            res+=a[i];
        }
    }
    if (pos1.first!=pos2.second&&pos1.second!=pos2.first)
    {
        res+=a[pos1.first]*a[pos1.second]+a[pos2.first]*a[pos2.second];
    } else if (pos1.second==pos2.first)
    {
        res+=a[pos1.first]*a[pos2.first]*a[pos2.second];
    } else if (pos2.second==pos1.first)
    {
        res+=a[pos2.first]*a[pos2.second]*a[pos1.second];
    }
    cout<<res;
    return 0;
}