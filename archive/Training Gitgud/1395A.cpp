#include <iostream>
using namespace std;
int a[4];
bool checkk()
{
    int cnt = 0;
    for (int i = 0; i < 4; ++i)
    {
        cnt += a[i]&1; 
    }
    return cnt < 2;
}
int main()
{
    int n;
    cin >> n; 
    while (n--)
    {
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        if (checkk() == true) cout << "YES" << endl; else
        {
            if (a[0] == 0 || a[1] == 0 || a[2] == 0) cout << "NO" << endl; else
            {
                a[0]--;
                a[1]--;
                a[2]--;
                a[3] += 3;
                if (checkk() == true) cout << "YES" << endl; else cout << "NO" << endl;
            }
            
        }
        
    }
    return 0;
}