#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
struct cautruc
{
    long long x,y;
};
cautruc batdau,ketthuc;
long long n,m,cost[53][53],x[4]={0,0,-1,1},y[4]={-1,1,0,0};
bool vis[53][53];
char a[53][53];
bool ngap[53][53];
queue <cautruc> q;
void ngapnuoc()
{
    for (long long i=1;i<=n;++i)
    {
        for (long long j=1;j<=m;++j)
            ngap[i][j]=0;
    }
    for (long long i=1;i<=n;++i)
    {
        for (long long j=1;j<=m;++j)
        {
            if (a[i][j]=='*'&&ngap[i][j]==0)
            {
                if (i-1>0&&a[i-1][j]=='.')
                {
                    a[i-1][j]='*';
                    ngap[i-1][j]=1;
                }
                if (i+1<=n&&a[i+1][j]=='.')
                {
                    a[i+1][j]='*';
                    ngap[i+1][j]=1;
                }
                if (j-1>0&&a[i][j-1]=='.')
                {
                    a[i][j-1]='*';
                    ngap[i][j-1]=1;
                }
                if (j+1<=m&&a[i][j+1]=='.')
                {
                    a[i][j+1]='*';
                    ngap[i][j+1]=1;
                }
            }
        }
    }
}
void bfs(cautruc point)
{
    q.push(point);
    cost[point.x][point.y]=0;
    vis[point.x][point.y]=true;
    while (!q.empty())
    {
        cautruc u=q.front();
        q.pop();
        ngapnuoc();
        for (long long j=0;j<4;++j)
        {
            long long tmp_x=u.x+x[j];
            long long tmp_y=u.y+y[j];
            if (vis[tmp_x][tmp_y]==false&&tmp_x>=1&&tmp_x<=n&&tmp_y>=1&&tmp_y<=m&&(a[tmp_x][tmp_y]=='.'||a[tmp_x][tmp_y]=='D'))
            {
                cautruc tmp;
                tmp.x=tmp_x;
                tmp.y=tmp_y;
                q.push(tmp);
                vis[tmp_x][tmp_y]=true;
                cost[tmp_x][tmp_y]=min(cost[tmp_x][tmp_y],cost[u.x][u.y]+1);
            } else if (vis[tmp_x][tmp_y]==true&&tmp_x>=1&&tmp_x<=n&&tmp_y>=1&&tmp_y<=m&&(a[tmp_x][tmp_y]=='.'||a[tmp_x][tmp_y]=='D'))
            {
                cost[tmp_x][tmp_y]=min(cost[tmp_x][tmp_y],cost[u.x][u.y]+1);
            }
        }
    }
}
int main()
{
    freopen("DROWN.inp","r",stdin);
    freopen("DROWN.out","w",stdout);
    cin>>n>>m;
    for (long long i=1;i<=n;++i)
    {
        for (long long j=1;j<=m;++j)
        {
            cin>>a[i][j];
            if (a[i][j]=='S')
            {
                batdau.x=i;
                batdau.y=j;
            }
            if (a[i][j]=='D')
            {
                ketthuc.x=i;
                ketthuc.y=j;
            }
        }
    }
    for (long long i=0;i<=n+1;++i)
        for (long long j=0;j<=m+1;++j)
            cost[i][j]=1e9;
   bfs(batdau);
   for (int i=1;i<=n;++i)
   {
        for (int j=1;j<=m;++j)
            cout<<vis[i][j]<<" ";
        cout<<endl;
   }
   cout<<endl;
    for (int i=1;i<=n;++i)
   {
        for (int j=1;j<=m;++j)
            cout<<a[i][j]<<" ";
        cout<<endl;
   }
    if (cost[ketthuc.x][ketthuc.y]==1e9) cout<<"IMPOSSIBLE"; else cout<<cost[ketthuc.x][ketthuc.y];
    return 0;
}