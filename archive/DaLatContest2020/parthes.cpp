#include <iostream>
#include <string>
#include <stack>
using namespace std;
string st;
stack <pair<int, char>> stackk, sta;
int ans;
int main()
{
    cin >> st;
    int cnt_o = 0;
    int cnt_c = 0;
    int n = st.size();
    for (int i = 0;i < n; ++i)
    {
        if (st[i] == '(') cnt_o++; else cnt_c++;
    }
    if (cnt_c != cnt_o)
    {
        cout<<-1;
        return 0;
    }
    for (int i = 0; i < n; ++i)
    {
        if (st[i] == '(')
        {
            stackk.push( {i, '('});
        } else
        {
            if (!stackk.empty() && stackk.top().second == '(')
            {
                stackk.pop();
            } else stackk.push( {i,')'});
        }
    }
    int k = stackk.size()/2;
    for(int i = 1; i < k; i--) stackk.pop();
    ans = stackk.top().first;
    ans = min(ans, n - stackk.top().first);
    stackk.pop();
    ans = min(ans, stackk.top().first + 1);
    ans = min(ans, n - stackk.top().first - 1);
    cout << ans;
    return 0;
}