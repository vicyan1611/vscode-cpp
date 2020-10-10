#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
const int Nmax = 55;
int n, x[Nmax], res[Nmax];
bool vis[Nmax];
struct bignum
{
    int deg;
    vector <int> num;
    bignum()
    {
        for (int i = 1; i <= 100; ++i)
        num.push_back(0);
    }
};
bignum f[Nmax];
string sth;
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
bignum inp(string tmp)
{
    bignum c;
    int cnt = -1;
    for (int i = tmp.size() - 1; i >= 0; --i)
    {
        c.num[++cnt] = tmp[i] - 48;
    }
    c.deg = tmp.size();
    return c;
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
    /*
    c.deg = a.deg + b.deg;
    int carry = 0;
    for (int i = 0; i < a.deg; ++i)
    {
        
        int tmp = carry;
        for (int j = 0; j <= i; ++j)
        {
            tmp += a.num[i] * b.num[i - j];
        }
        c.num[i] = tmp % 10;
        carry = tmp / 10;
    }
    while (carry != 0)
    {
        ++c.deg;
        c.num[c.deg-1] = carry % 10;
        carry /= 10;
    }
    while (c.deg > 1 && c.num[c.deg-1] == 0) c.deg--;
    return c;*/
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
void solve1()
{
    for (int i = 1; i <= n; ++i)
        vis[i] = false;
    bignum a = inp("0");
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < x[i]; ++j)
        {
            if (!vis[j])
            {
                a = a + f[n-i];
            }
        }
        vis[x[i]] = true;
    }
    bignum b = inp("1");
    outp(a + b);
}
void solve2()
{
    for (int i = 1; i <= n; ++i) vis[i] = res[i] = 0;
    bignum k = inp(sth);
    for (int i = 1; i <=n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (!vis[j])
            {
                if (cmp(k, f[n-i]) == 1)
                {
                    k = k - f[n-i];
                } else
                {
                    res[i] = j;
                    vis[j] = true;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i] == false) res[n] = i;
    }
    for (int i = 1; i<=n; ++i)
        cout << res[i] << " ";
}
int main()
{
    freopen("HV.inp","r",stdin);
    freopen("HV.out","w",stdout);
    cin >> n;
    bignum a = inp("1");
    f[1] = a;
    for (int i = 2; i <= n; ++i)
    {
        stringstream s;
        string tmp;
        s << i;
        s >> tmp;
        a = a * inp(tmp);
        f[i] = a;
    }
    outp(a);
    cout << endl;
    int num;
    while (cin >> num)
    {
        if (num == 1)
        {
            for (int i = 1; i <= n; ++i)
                cin >> x[i];
            solve1();
        } else if (num == 2)
        {
            cin >> sth;
            solve2();
        }
        cout << endl;
    }
    return 0;
}