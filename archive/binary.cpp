#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
const int Nmax = 105;
int n, k;
string sth;
int x[Nmax], res[Nmax];
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
bignum f[Nmax], dp[Nmax][Nmax];
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
bignum trau(int i, int time)
{
    if (time > k) return dp[i][time] = inp("0");
    if (i > n) return dp[i][time] = inp("1");
    bignum &res = dp[i][time];
    if (cmp(res, tru1) == 1) return res;
    res = inp("0");
    if (time < k)
    {
        res = res + trau(i + 1, time + 1);
        res = res + trau(i + 1, time);
    } else
    {
        res = res + trau(i+1, time);
    }
    return res;
}
void solve2()
{
    bignum a = inp(sth);
    int node = 1;
    int cnt = 0;
    while (node <= n)
    {
        if ( cmp(dp[node+1][cnt], a) == -1)
        {
            
            res[node] = 1;
            node++;
            cnt++;
            a = a - dp[node][cnt-1];
        } else
        {
            res[node] = 0;
            node++;
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << res[i] << " ";
}
void solve1()
{
    bignum ans = inp("1");
    int i = 1, j = 0;
    int it = 1;
    while (it <= n)
    {
        if (x[it] == 1)
        {
            i++;
            j++;
            stringstream s;
            ans = ans + dp[i][j-1];
        } else
        {
            i++;
        }
        
        it++;
    } 
    outp(ans);
}
int main()
{
    freopen("binary.inp","r",stdin);
    freopen("binary.out","w",stdout);
    cin >> n >> k;
    bignum a = inp("1");
    tru1.deg = 1;
    tru1.num[0] = -1;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j<= k; ++j)
            dp[i][j] = tru1;
        f[1] = a;
    for (int i = 2; i <= n; ++i)
    {
        a = a * inp("2");
        f[i] = a;
    }
    outp(trau(1,0));
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