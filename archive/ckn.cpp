#include <iostream>
#include <vector>
using namespace std;
struct bignum
{
    int deg;
    vector <int> num;
    bignum()
    {
        for (int i = 1; i <= 50; ++i)
        {
            num.push_back(0);
        }
    }
};
bignum tru1;
bignum inp(string a)
{
    int cnt = -1;
    bignum c;
    for (int i = a.size() - 1; i >= 0; --i)
    {
        c.num[++cnt] = a[i] - 48;        
    }
    c.deg = a.size();
    return c;
}
void outp(bignum a)
{
    for (int i = a.deg - 1; i >= 0; --i)
    {
        cout << a.num[i];
    }
}
int cmp(bignum a, bignum b)
{
    if (a.deg > b.deg) return 1;
    if (a.deg < b.deg) return -1;
    for (int i = a.deg - 1; i >= 0; --i)
    {
        if (a.num[i] == b.num[i]) continue;
        if (a.num[i] > b.num[i]) return 1;
        if (a.num[i] < b.num[i]) return -1;
    }
    return 0;
}
bignum operator + (bignum a, bignum b)
{
    bignum c;
    c.deg = max(a.deg, b.deg);
    int carry = 0;
    for (int i = 0; i < c.deg; ++i)
    {
        int tmp = a.num[i] +  b.num[i] + carry;
        c.num[i] = tmp % 10;
        carry = tmp / 10;
    }
    if (carry != 0)
    {
        c.deg++;
        c.num[c.deg-1] =  1;
    }
    return c;
}
bignum operator - (bignum a, bignum b)
{
    bignum c;
    c.deg = a.deg;
    int carry = 0;
    for (int i = 0; i < c.deg; ++i)
    {
        int hieu = a.num[i] - b.num[i] - carry;
        if (hieu < 0)
        {
            hieu += 10;
            carry = 1;
        } else carry = 0;
        c.num[i] = hieu;
    }
    while (c.deg > 0 && c.num[c.deg - 1] == 0) c.deg--;
    return c;
}
bignum operator * (bignum a, bignum b)
{
    bignum c;
    c.deg = a.deg + b.deg;

    for (int i = 0; i < a.deg; ++i) 
    {
        for (int j = 0; j < b.deg; ++j) 
        {
            int k = i + j;
            int tmp = a.num[i] * b.num[j]; 
            c.num[k] += tmp % 10;
            if (c.num[k] >= 10)
            {
                c.num[k+1] += c.num[k] /10;
                c.num[k] %= 10; 
            }
            c.num[k+1] += tmp / 10;
            if (c.num[k+1] >= 10)
            {
                c.num[k+2] += c.num[k+1] /10;
                c.num[k+1] %= 10; 
            }
        }
    }
    while (c.num[c.deg-1] == 0 && c.deg > 1) --c.deg;    
    return c;
}
int n, k;
int main()
{
    cin >> n >> k;
    cotu
    return 0;
}