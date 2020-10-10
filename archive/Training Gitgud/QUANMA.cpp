#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int x[8]={-2,-1,1,2,2,1,-1,-2};
int y[8]={1,2,2,1,-1,-2,-2,-1};
int n,m,x1,ay1,x2,y2,cost[1003][1003];
vector < pair <int,int> > f[1003][1003];
queue < pair<int,int> > q;
bool vis[1003][1003];
void bfs(int a,int b)
{
    pair <int,int> tmp;
    tmp.first=a;
    tmp.second=b;
    q.push(tmp);
    vis[a][b]=true;
    cost[a][b]=0;
    while (!q.empty())
    {
        pair <int,int> u=q.front();
        q.pop();
        for (auto v:f[u.first][u.second])
        {
            if (vis[v.first][v.second]==false)
            {
                vis[v.first][v.second]=true;
                cost[v.first][v.second]=min(cost[v.first][v.second],cost[u.first][u.second]+1);
                q.push(v);
            } else
            {
                cost[v.first][v.second]=min(cost[v.first][v.second],cost[u.first][u.second]+1);
            }
            
        }
    }
}
void ghepcanh(int a,int b)
{
    for (int i=0;i<8;++i)
    {
        int tmp_x=a+x[i];
        int tmp_y=b+y[i];
        if (tmp_x>=1&&tmp_x<=n&&tmp_y>=1&&tmp_y<=m)
        {
            f[a][b].push_back({tmp_x,tmp_y});
        }
    }
}
int main()
{
    cin>>n>>m>>x1>>ay1>>x2>>y2;
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            ghepcanh(i,j);
        }
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            cost[i][j]=1e9;
    bfs(x1,ay1);
    if (vis[x2][y2]==false) cout<<"-1"; else cout<<cost[x2][y2];
    return 0;
}