#include <iostream>
#include <map>
using namespace std;
int sto[100004], num4, num2;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sto[x]++;
        if (sto[x] == 2)
        {
            num2++;
        } else if (sto[x] == 4)
        {
            num4++;
            num2--;
            sto[x] = 0;
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        char ch;
        int num;
        cin >> ch >> num;
        if (ch == '-')
        {
            sto[num]--;
            if (sto[num] == 1)
            {
                num2--;
            }
            if (sto[num] == -1)
            {
                num2++;
                num4--;
                sto[num] = 3;
            }
            
        } else
        {
            sto[num]++;
            if (sto[num] == 2)
            {
                num2++;
            } else if (sto[num] == 4)
            {
                num4++;
                num2--;
                sto[num] = 0;
            }
        }
        if ( (num2 > 1 && num4 == 1) || (num4>1) ) cout << "YES" << endl; else cout << "NO" << endl;
    }  
    return 0;
}