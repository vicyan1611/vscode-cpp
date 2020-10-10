#include <bits/stdc++.h>
using namespace std;
const int Ntest = 100;
const string Name = "thidau";
int a[12], b[12];
int rando(int l, int h)
{
    return l +  (rand() * 105) % (h - l + 1);
}
int main()
{
    srand(time(NULL));
    for (int i = 1; i <= Ntest; ++i)
    {
        ofstream in ("thidau.inp");
        int n = rando(1,10);
        int k = rando(1,5);
        for (int j = 1; j <= n; ++j)
        {
            a[j] = rando(a[j-1], 100);
        }
        for (int j = 1; j <= n; ++j)
        {
            b[j] = rando(1, 100);
        }
        in << n << " " << k << endl;
        for (int i = 1; i <= n; ++i)
        {
            in << a[i] << " ";
        }
        in << endl;
        for (int i = 1; i <= n; ++i)
        {
            in << b[i] << " ";
        }
        in.close();
        system("thidau.exe");
        system("thidautrau.exe");
        if (system("fc thidau.out thidau.ans") != 0)
        {
            cout << "WRONG";
            return 0;
        }
        cout << "YES" << endl;

    }
    return 0;
}