#include <bits/stdc++.h>

using namespace std;

struct OwnTime
{
    int h, m, s;
    OwnTime (int _h = 0, int _m = 0, int _s = 0)
    {
        h = _h;
        m = _m;
        s = _s;
    }
    OwnTime operator + (const OwnTime &b)
    {
        OwnTime ans;
        ans.s = s + b.s;
        ans.m = m + b.m + (ans.s / 60);
        ans.h = h + b.h + (ans.m / 60);
        ans.s %= 60;
        ans.m %= 60;
        return ans;
    }
    string TimeToString ()
    {
        string ans;
        ans = (h / 10 + '0') ;
        ans += (h % 10 + '0') ;
        ans += ":" ;
        ans += (m / 10 + '0');
        ans += (m % 10 + '0');
        ans += ":";
        ans += (s / 10 + '0');
        ans += (s % 10 + '0');
        return ans;
    }
};

OwnTime SecondToTime (const int sec)
{
    OwnTime ans;
    ans.m = sec / 60;
    ans.s = sec % 60;
    return ans;
}


OwnTime MinuteToTime (const string &s)
{
    OwnTime ans;
    ans.m = s[0] - '0';
    ans.s = (s[2] - '0') * 10 + (s[3] - '0');
    return ans;
}

int n, f;

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> f;
    OwnTime Tmp, Sum;
    string s;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        Sum = Sum + MinuteToTime (s);
    }
    Tmp = SecondToTime(f * (n - 1));
    int rem = Sum.s < Tmp.s;
    Sum.s = Sum.s + (Sum.s < Tmp.s)*60 - Tmp.s;
    Tmp.m += rem;
    Sum.h -= (Sum.m < Tmp.m);
    Sum.m = Sum.m + (Sum.m < Tmp.m)*60 - Tmp.m;
    cout << Sum.TimeToString();
    return 0;
}