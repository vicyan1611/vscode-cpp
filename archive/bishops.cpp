#include <iostream>
using namespace std;
int main()
{
    long long n, x1, x2, y1, y2;
    cin >> n;
    cin >> x1 >> y1 >> x2 >> y2;
    if (abs(x1 - x2) == abs(y1 - y2) || ((x1 + y1) % 2 == (x2 + y2)%2)) cout << "yes"; else cout << "no";
    return 0;
}