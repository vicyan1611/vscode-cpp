#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
bool check[1000002];
int re[1000005];

using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while (t--)
    {
        int cnt;
        cin>>n;
        check[0]=true;
        check[1]=true;
        re[1]=0;
        re[2]=1;
        cnt=2;
        int i= (int) pow(n,0.5);
        i++;
        for (i;i>=1;--i)
        {
            if (check[n/i]==false)
            {
                check[n/i]=true;
                re[++cnt]=n/i;
            }
        }
        for (int i=1;i<=cnt;++i)
            check[re[i]]=false;
        cout<<cnt<<endl;
        for (int i=1;i<=cnt;++i)
            cout<<re[i]<<" ";
        cout<<endl;
    }
    return 0;
}