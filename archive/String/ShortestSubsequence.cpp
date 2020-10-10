#include <iostream>
#include <string>
using namespace std;
string st;
int Neext[1000005][5];
int a[1000005];
int main()
{
    cin >> st;
    int n = st.size();
    for (int i = 0; i < st.size(); ++i)
    {
        if (st[i] == 'A') a[i+1] = 0;
        if (st[i] == 'C') a[i+1] = 1;
        if (st[i] == 'G') a[i+1] = 2;
        if (st[i] == 'T') a[i+1] = 3;
    }
    for (int i = 0; i <= n + 1; ++i)
        for (int j = 0; j < 5; ++j)
            Neext[i][j] = 1e9;
    for (int i = 0; i < n; ++i)
    {
        Neext[i][a[i+1]] = i+1;
    }
    for (int i = n; i >= 0; --i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (Neext[i][j] != 1e9) continue;
            Neext[i][j] = Neext[i+1][j];
        }
    }
    int x = 0;
    string res = "";
    int tmp; 
    int rem;
   // cout << Neext[0][1] << " " << Neext[0][3] << endl;
    while (x <= n)
    {
        tmp = -1;
        rem = -1;
        for (int i = 0; i < 4; ++i)
        {
            if (tmp < Neext[x][i])
            {
                rem = i;
                tmp = Neext[x][i];
            }
        }
        if (rem == 0) res = res + "A"; else if (rem == 1) res = res + "C"; else if (rem == 2) res = res + "G"; else if (rem == 3) res = res + "T";
        //cout << x << " " << rem << endl;
        x = tmp;
    }
    cout << res;
    return 0;
}