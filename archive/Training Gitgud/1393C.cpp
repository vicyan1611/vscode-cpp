#include <iostream>
#include <algorithm>
using namespace std;
int n, f[100005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i <= n; i++)
        {
            f[i] = 0;
        }
        
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            f[x]++;
        }
        sort(1 + f, 1 + f + n, greater <int> ());
        int maxx = f[1];
        int cnt = 1;
        while (f[cnt] == f[cnt+1]) cnt++;
        cout << (n - cnt) / (maxx - 1) - 1 << endl;
    }
    return 0;
}