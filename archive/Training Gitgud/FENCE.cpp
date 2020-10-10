#include <iostream>
#define endl '\n'
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
struct cautruc
{
    int vt,type,heigh,num,place=0;
};
cautruc point[200005];
vector <int> heapA={0},heapB={0};
int pos[100005];
bool cmp(cautruc a,cautruc b)
{
    if (a.vt!=b.vt) return a.vt<b.vt; else
    {
        if (a.type!=b.type)
            return a.type<b.type; else return a.heigh<b.heigh;
    }
    
}
int bnrs(vector <int> vect,int x)
{
    int l=0,r=vect.size()-1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (vect[mid]==x) return mid; else if (vect[mid]>x) l=mid+1; else r=mid-1;
    }
    return -1;
}
int main()
{
    int n;
    freopen("FENCE.inp","r",stdin);
    freopen("FENCE.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        int x,w,h;
        cin>>x>>w>>h;
        point[i].vt=x;
        point[i+n].vt=x+w;
        point[i].type=1;
        point[i+n].type=2;
        point[i].heigh=h;
        point[i+n].heigh=h;
        point[i].num=i;
        point[i+n].num=i;
    }
    n*=2;
    sort(1+point,1+point+n,cmp);
    for (int i=1;i<=n;++i)
    {
        if (point[i].type==1)
        {
            pos[point[i].num]=i;
        }
    }
    make_heap(heapA.begin(),heapA.end());
    make_heap(heapB.begin(),heapB.end());
    int res=0;
    for (int i=1;i<=n;++i)
    {
        if (point[i].type==1)
        {
            if (point[i].heigh>heapA.front())
            {
                heapA.push_back(point[i].heigh);
                point[i].place=1;
            } else
            {
                heapB.push_back(point[i].heigh);
                point[i].place=2;
            }
        } else
        {
            if (point[i].type==1)
            {
                if (point[pos[point[i].num]].place==2)
                {
                    auto vt=bnrs(heapB,point[i].heigh);
                    if (vt!=-1) heapB.erase(heapB.begin()+vt);
                } else
                {
                    auto vt=bnrs(heapA,point[i].heigh);
                    if (vt!=-1) heapA.erase(heapA.begin()+vt);
                    res++;
                    while (heapA.front()<heapB.front())
                    {
                        res++;
                        heapB.pop_back();
                    } 
                }
                
            }
        }       
    }
    cout<<res<<endl;
    return 0;
}