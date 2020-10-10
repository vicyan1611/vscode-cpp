	
#include <bits/stdc++.h>
 using namespace std;
int a[501][501],d[501][501],n;
bool f1[501][501],f2[501][501],F[501][501];
 
int main()
{
    freopen("PARIGAME.inp","r",stdin);
    freopen("PARIGAME.ans","w",stdout);
    int test;
    scanf("%d",&test);
    for(int ii = 1;ii<=test;ii++)
    {
         scanf("%d",&n);
         for(int i = 1;i<=n;i++)
             d[0][i] = 0;
         for(int i = 1;i<=n;i++)
         {
             int k = 0;
             for(int j = 1;j<=n;j++)
             {
                 scanf("%d",&a[i][j]);
                 a[i][j] = a[i][j]%2;
                 d[i][j] = (d[i-1][j] + a[i][j])%2;
                 k = (k+a[i][j])%2;
                 if(d[i][j]== 0) f1[i][j] = true;
                 else f1[i][j] = false;
                 if(k == 0) f2[i][j] = true;
                 else f2[i][j] = false;
             }
         }
         for(int i = 0;i<=n;i++)
         {
              F[i][0] = false;
              F[0][i] = false;
         }
         for(int i = 1;i<=n;i++)
             for(int j = 1;j<=n;j++)
             {
                 F[i][j] = false;
                 if(f1[i][j] && !F[i][j-1]) F[i][j] = true;
                 if(f2[i][j] && !F[i-1][j]) F[i][j] = true;
                // printf("%d %d %d\n",i,j,F[i][j]);
             }
         if(F[n][n]) cout << "YES" << endl; else
         cout << "NO" << endl;
                          
    }
    //getch();
}
 