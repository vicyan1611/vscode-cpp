#include <iostream>
#include <fstream>
using namespace std;
int nheap,cnt0,dem,a[100005],n;
pair <int,int> heap[100005];
bool cmp(int i,int j)
{
    int tmp1=heap[i].second-heap[i].first+1;
    int tmp2=heap[j].second-heap[j].first+1;
    if (tmp1!=tmp2) return tmp1<tmp2; else return heap[i].first>heap[j].first;
}
void upheap(int i)
{
    int j=i/2;
    if (j==0||cmp(i,j)) return;
    swap(heap[i],heap[j]);
    upheap(j);
}
void downheap(int i)
{
    int j=i*2;
    if (j<nheap&&(j,j+1)) j++;
    if (j>nheap||cmp(j,i)) return;
    swap(heap[i],heap[j]);
    downheap(j);

}
void pushheap(int l,int r)
{
    nheap++;
    heap[nheap].first=l;
    heap[nheap].second=r;
    upheap(nheap);
}
pair <int,int> popheap()
{
    pair <int,int> res=heap[1];
    swap(heap[1],heap[nheap]);
    nheap--;
    downheap(1);
    return res;

}
void solve(pair <int,int> x)
{
    dem++;
    int l=x.first;
    int r=x.second;
    if ((r-l+1)%2==0)
    {
        cnt0--;
        a[(l+r-1)/2]=dem;
        int mid=(l+r-1)/2;
        if (mid-1>0) pushheap(l,mid-1);
        if (mid+1<=n) pushheap(mid+1,r);
    }  else
    {
        cnt0--;
        a[(l+r)/2]=dem;
        int mid=(l+r)/2;
        if (mid-1>0) pushheap(l,mid-1);
        if (mid+1<=n) pushheap(mid+1,r);
    }
    if (cnt0>0)
    {
        pair <int,int> h=popheap();
        solve(h);
    }  else
    {
        for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
        cout<<endl;
    }
    

}
int main()
{
    freopen("1353D.inp","r",stdin);
    freopen("1353D.out","w",stdout);
    int t;
    cin>>t;
    while (t--)
    {
        nheap=0;
        cin>>n;
        cnt0=n;
        dem=0;
        pushheap(1,n);
        pair <int,int> h=popheap();
        solve(h);
    }
    return 0;
}