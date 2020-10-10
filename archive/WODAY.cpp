#include <iostream>
#include <fstream>
#include <set>
using namespace std;
bool chec[200005];
long long res = 0;
void solve(long long n)
{
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            long long x = (i - 1) * (n / i + 1);
            if (chec[x] == false)
            {
                res++;
                chec[x] = true;
                solve(x);
            } 
        }
    }
}
int main()
{
    freopen("WODAY.inp","r",stdin);
    freopen("WODAY.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n;
    cin >> n;
    solve(n);
    cout << res << endl;
    for (long long i = 0; i <= n; ++i)
        if (chec[i]) cout << i << " ";
    return 0;
}