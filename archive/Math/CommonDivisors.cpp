#include <iostream>
using namespace std;
int cnt[1000005];
int res = 0;
void sang()
{
    for (int i = 1; i <= 1e6; ++i)
    {
        bool check1 = false, check2 = false;
        for (int j = i; j <= 1e6; j += i)
        {
            if (cnt[j] > 0)
            {
                if (cnt[j] == 1)
                {
                    if (check1 == false) check1 = true; else if (check1 == true && check2 == false) check2 = true;
                } else
                {
                    check1 = true;
                    check2 = true;
                }
                
            }
        }
        if (check1 == true && check2 == true) res = max(res, i);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    sang();
    cout << res;
    return 0;
}