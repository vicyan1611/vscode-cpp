/*     __//
cf  /.__.\
    \ \/ /
 '__/    \
  \-      )
   \_____/
_____|_|____
     " " */
#include <bits/stdc++.h>
#define task "adwins"
#define endl '\n'
using namespace std;
const int M = 2e5 + 5;
struct rec{
    int a1;
    int a2;
    int b1;
    int b2;
    bool iscut(rec a){
        bool ta = min(b1, a.b1) < max(a1, a.a1);
        bool tb = min(b2, a.b2) < max(a2, a.a2);
        return (ta || tb);
    }
}a[M];

int n;

void enter(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        a[i] = {a1, a2, b1, b2};
    }
}

int solve(){
    int cnt = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j){
            bool ta = a[i].iscut(a[j]);
            if(!ta)
                ++cnt;
        }
    return cnt;
}

/*long long mega_solve(){

}*/

void query(){
    enter();
    if(n <= 20000)
        cout << solve() << "\n";
    else
        cout << ((long long)n * (n - 1)) / 2 << "\n";
}

void enter_query(){
    int t;
    cin >> t;
    while(t--)
        query();
}

int main()
{
   //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    enter_query();   
    return 0;
}