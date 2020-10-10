#include <iostream>
#include <fstream>
using namespace std;
const int Nmax = 3000005;
int f[Nmax];
bool notPrime[Nmax];
bool handle(int x)
{
    int res = 0;
    while (x != 0)
    {
        res += x%10;
        x /= 10;
    }
    if (res % 5 == 0) return true; else return false; 
}
void etho()
{
    notPrime[1] = true;
    notPrime[0] = true;
    for (int i = 2; i*i <= Nmax; ++i)
    {
        if (notPrime[i] == false)
        {
            for (int j = i*2; j <= Nmax; j += i)
                notPrime[j] = true;
        }
    }
    for (int i = 1; i <= Nmax; ++i)
    {
        if (notPrime[i] == false)
        {
            if (handle(i) == true) f[i] = f[i-1] + 1; else f[i] = f[i-1];
        } else f[i] = f[i-1];
    }
}
int main()
{
    etho();
    freopen("sprime.inp","r",stdin);
    freopen("sprime.out","w",stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int l, r;
        cin >> l >> r;
        cout << f[r] - f[l-1] << endl;
    }
    return 0;
}