#include <iostream>
using namespace std;
void for4()
{
    int tich=1;
    for (int i=1;i<=3;++i)
    {
        cout<<tich<<" * "<<i+1<<" = "<<tich*(i+1)<<endl; 
        tich*=i+1;
    }
}
void for5()
{
    cout<<5<<" * "<<4<<" = "<<20<<"\n";
    cout<<2<<" + "<<3<<" = "<<5<<"\n";
    cout<<5<<" - "<<1<<" = "<<4<<"\n";
    cout<<20<<" + "<<4<<" = "<<24<<"\n";
}
int main()
{
    int n;
    cin>>n;
    if (n<4)
    {
        cout<<"NO";
        return 0;
    } 
    cout<<"YES"<<endl;
    
    if (n%2==0)
    {
        for4();
        for (int i=6;i<=n;i+=2)
        {
            cout<<i<<" - "<<i-1<<" = "<<1<<"\n";
            cout<<24<<" * "<<1<<" = "<<24<<"\n";
        }
        return 0;
    }   
    for5();
    for (int i=7;i<=n;i+=2)
    {
        cout<<i<<" - "<<i-1<<" = "<<1<<"\n";
        cout<<24<<" * "<<1<<" = "<<24<<"\n";
    }
    return 0;
}