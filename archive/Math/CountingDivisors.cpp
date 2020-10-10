#include <iostream>
using namespace std;
long long res[1000005];
void sang()
{
    for (int i = 1; i <= 1e6; ++i)
        for (int j = i; j <= 1e6; j += i) ++res[j];
}
int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    sang();
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << res[n] << endl;
    }
    return 0;
}