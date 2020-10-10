#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
double FtoC(double F)
{
    return (double) 5/9*(F-32);
}
double CtoF(double C)
{
    return (double) 9/5*C+32;
}
string st;
int main()
{
    cin>>st;
    if (st[st.size()-1]=='F'||st[st.size()-1]=='f')
    {
        stringstream ss;
        st.pop_back();
        ss<<st;
        double num;
        ss>>num;
        cout<<fixed<<setprecision(2)<<FtoC(num)<<"C";
    } else
    {
        
        stringstream ss;
        st.pop_back();
        ss<<st;
        double num;
        ss>>num;
        cout<<fixed<<setprecision(2)<<CtoF(num)<<"F";
    }
    return 0;
}