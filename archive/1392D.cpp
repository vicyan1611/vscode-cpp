#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
const int Nmax = 200005;
char a[Nmax];
vector <int> ns;
int main()
{
    freopen("1392D.inp","r",stdin);
    freopen("1392D.out","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        int cnt = 0;
        for (int i = 2; i <= n; ++i)
        {
            if (a[i] == a[i-1]) cnt++;
        }
        if (cnt == n-1)
        {
            cout << (n+2)/3 << endl;;
            continue;
        }
        cnt = 1;
        ns.clear();
        for (int i = 2; i <= n; ++i)
        {
            if (a[i] != a[i-1])
            {
                ns.push_back(cnt);
                cnt = 1;
            } else cnt++;
        }
        int res = 0;
        ns.push_back(cnt);
        if (ns.size() > 1)
        {
            if (a[n] == a[1]) 
            {
                ns[ns.size()-1] += ns[0];
                ns[0] = -1;
            } 
        }
        for (int v: ns)
        {
            if (v > 2) res += v/3;
        }
        cout << res << endl;
    }
    return 0;
}