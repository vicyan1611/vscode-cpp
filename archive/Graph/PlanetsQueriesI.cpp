#include <iostream>
#include <vector>
using namespace std;
const int Nmax = 2e5 + 5;
int n, q;
vector <int> adj[Nmax];
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        adj[i].push_back(x);
    }
    while (q--)
    {
        int k, x;
        cin >> k >> x;
        
    }
    return 0;
}