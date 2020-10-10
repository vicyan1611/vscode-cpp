#include <iostream>
using namespace std;
pair <int,int> edge[49950];
bool checkprime(int i)
{
    if (i==1||i==0) return false;
    for (int j = 2; j*j <= i; j++)
    {
        if (i%j==0) return false;
    }
    return true;
    
}
int main()
{
    int n;
    cin>>n;
    if (n==3)
    {
        cout<<3<<endl<<"1 2"<<endl<<"2 3"<<endl<<"1 3";
    } else if (n<3) cout<<-1; else
    {
        int m=0;
        for (int i=1;i<=n;++i)
        {
            if (i!=n)
            {
                edge[i].first=i;
                edge[i].second=i+1;
            } else
            {
                edge[i].first=n;
                edge[i].second=1;
            }
            m++;
        }
        int i=0;
        while (checkprime(m)==false)
        {
            ++m;
            ++i;
            edge[m].first=i;
            edge[m].second=i+n/2;
        }
        cout<<m<<endl;
        for (int i=1;i<=m;++i)
        {
            cout<<edge[i].first<<" "<<edge[i].second;
            cout<<endl;
        }
    }
    return 0;
}