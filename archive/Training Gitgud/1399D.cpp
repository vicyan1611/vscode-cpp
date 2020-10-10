#include <iostream>
#include <stack>
#include <vector>
using namespace std;
stack <int> ze,on;
vector <int> res;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        res.clear();
        while (!on.empty())
        {   
            on.pop();
        }
        while (!ze.empty())
        {
            ze.pop();
        }
        int n;
        cin>>n;
        int k=0;
        for (int i = 0; i < n; i++)
        {
            char x;
            cin>>x;
            if (x == '0')
            {
                if (on.empty())
                {
                    ++k;
                    res.push_back(k);
                    ze.push(k);
                } else
                {
                    res.push_back(on.top());
                    ze.push(on.top());
                    on.pop();
                }
                
            } else
            {
                if (ze.empty())
                {
                    ++k;
                    res.push_back(k);
                    on.push(k);
                } else
                {
                    res.push_back(ze.top());
                    on.push(ze.top());
                    ze.pop();
                }
                
            }
            
        }
        cout<<k<<endl;
        for (auto v:res)
            cout<<v<<" ";
        cout<<endl;
    }
    return 0;
}