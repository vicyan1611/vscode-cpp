#include <iostream>
#include <string>
#include <fstream>
using namespace std;
ifstream fi ("SL.inp");
ofstream fo ("SL.out");
struct cautruc
{
    string st;
    int size,val;
};
cautruc a[10];
string st;
int main()
{
    a[0]={"te",4,12};
    a[1]={"g",4,9};
    a[2]={"meg",4,4};
    a[3]={"k",4,3};
    a[4]={"d",4,-1};
    a[5]={"c",5,-2};
    a[6]={"mil",5,-3};
    a[7]={"mic",5,-4};
    a[8]={"n",4,-9};
    a[9]={"met",5,0};
    fi>>st;
    int n=st.size();
    st=" "+st;
    int i=1;
    int res=0;
    while (i<=n)
    {
        string temp="";
        int cnt=0;
        bool checkk=false;
        while (checkk==false)
        {
            temp+=st[i];
            cnt++;
            for (int j=0;j<=9;++j)
            {
                if (a[j].st==temp)
                {
                    checkk=true;
                    i+=(a[j].size-cnt);
                    res+=a[j].val;
                    break;
                }
            }
        }
        if (st[i]=='^') break;
    }
    cout<<res;
    return 0;   
}