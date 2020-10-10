    /*     __//
    cf  /.__.\
        \ \/ /
    '__/    \
    \-      )
    \_____/
    _____|_|____
        " " */
    #include <bits/stdc++.h>
    #define task "matrix"
    #define endl '\n'
    using namespace std;
    const long long md = 1e9 + 7;
    long long m, n, f[1000006];
    long long chiadetri(long long a, long long n)
    {
        if (n == 1) return a % md;
        if (n == 0) return 1;
        long long tmp = chiadetri(a, n / 2);
        tmp *= tmp;
        if (tmp > md) tmp %= md;
        if (n & 1)
            return (tmp * (a % md)) % md;
        return tmp;
    }
    int main()
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        cin >> m >> n;
        long long res = 1;
        f[0] = 1;
        for (int i = 1; i < min(n, m); ++i)
        {
            f[i] = (f[i-1] * i) % md;
            res *= chiadetri(f[i], 2);
            cout << f[i] << " " << res << endl;
            if (res > md) res %= md;                                                   
        }
        f[min(n, m)] = (f[min(n, m) - 1] * min(m, n)) % md;
        res *= chiadetri(f[min(m, n)], max(n, m) - min(n,m) + 1); 
        if (res > md) cout << res % md << endl; else cout << res << endl;
        return 0;
    }