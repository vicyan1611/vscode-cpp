#include <iostream>
using namespace std;
const int Nmax = 200005;
int n, a[Nmax];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        bool checkhac = false;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 2; i <= n;++i)
        {
            if (a[i] != a[i-1])
            {
                checkhac = true;
                break;
            }
        }
        if (checkhac == false) cout << n << endl; else cout << 1 << endl;
    }
    
    

    return 0;
}