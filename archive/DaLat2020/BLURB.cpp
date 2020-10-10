#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int n;
set <int> s;
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        if (s.insert(x).second) cout<<0<<" "; else cout<<1<<" ";
    }
    return 0;
}