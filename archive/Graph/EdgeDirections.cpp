#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
const int Nmax = 1e5 + 5;
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        cout << min(u, v) << " " << max(u, v) << endl;
    }
    return 0;
}