#include <bits/stdc++.h>
using namespace std;
const int iTest = 1e4;
long long ran(long long l, long long h) 
{
    return l + ((long long) rand() % (h - l + 1));
}
int main()
{
    srand(time(NULL));
    for (int i = 1; i <= iTest; ++i)
    {
        cout << "TEST " << i << endl;
        ofstream inp("sum1g.inp");
        long long n = ran(3, 100);
        inp << n << endl;
        for (int j = 1; j <= n; ++j)
        {
            inp << ran(30, 1000) << " ";
        }
        inp.close();
        system("sum1g.exe");
        system("sum1gtrau.exe");
        if (system("fc sum1g.out sum1g.ans") != 0)
        {
            cout << " WRONG !!";
            return 0;
        } else cout << " YES !!"; 
    }
    return 0;
}