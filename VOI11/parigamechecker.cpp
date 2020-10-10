#include <bits/stdc++.h>
using namespace std;
const int Ntest = 100;
int ran(int l, int h)
{
    return l + (rand() * 9999) % (h - l + 1);
}
int main()
{
    srand(time(NULL));
    for (int i = 1; i <= Ntest; ++i)
    {
        ofstream inp("parigame.inp");
        int n = ran(2, 4);
        inp << 1 << endl << n << endl;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                inp << ran(3, 10) << " ";
            }
            inp << endl;
        }
        system("parigame.exe");
        system("parigametrau.exe");
        if (system("fc parigame.out parigame.ans") != 0)
        {
            cout << "WRONG" << endl;
            return 0;
        } else cout << "YES" << endl;
    }
    return 0;
}