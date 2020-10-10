#include <iostream>
using namespace std;
pair <int, int> s;
bool vis[1005][1005];
int main()
{
    int n, m;
    cin >> n >> m >> s.first >> s.second;
    cout << s.first << " " << s.second;
    while(s.first - 1 >= 1)
    {
        s.first--;
        cout << s.first << " " << s.second << endl;
    } 
    return 0;
}