#include <iostream>
using namespace std;
const int md = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    long long n1 = 1;
    long long acyclic_num = 1;
    for (int i = 2; i <= n; ++i)
    {
        n1 = (n1 * i) % md;
        acyclic_num = (acyclic_num * 2) % md;
    }
    cout << (n1 - acyclic_num + md) % md;
    return 0;
}