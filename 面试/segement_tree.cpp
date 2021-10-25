#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const static int N = 100010;
typedef long long ll;
ll A[N],tree[4 * N],tag[4 * N];
void push_up(int rt)
{
    tree[rt] = tree[rt << 1] + tree[rt << 1|1];
}
void push_down(int rt,int l,int r)
{
    if(tag[rt] != 0)
    {
        int mid = (l + r) >> 1;
        ll lazy = tag[rt];
        tree[rt << 1] += (mid - l + 1) * lazy;
        tree[rt << 1|1] += (r - mid) * lazy;
        tag[rt << 1] += lazy;
        tag[rt << 1|1] += lazy;
        tag[rt] = 0;
    }
}
void build(int rt,int l,int r)
{
    if(l == r)
    {
        tree[rt] = A[r];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1,l,mid);
    build(rt << 1|1,mid + 1,r);
    push_up(rt);
}
void updateRange(int rt,int l,int r,int start,int end,ll delta)
{
    if(start <= l && end >= r)
    {
        tree[rt] += (r - l + 1) * delta;
        tag[rt] += delta;
        return;
    }
    push_down(rt,l,r);
    int mid = (l + r) >> 1;
    if(start <= mid) updateRange(rt << 1,l,mid,start,end,delta);
    if(end >= mid + 1)updateRange(rt <<1|1,mid + 1,r,start,end,delta);
    push_up(rt);
}
ll rangeQuery(int rt,int l,int r,int start,int end)
{
    if(start <= l && end >= r)
        return tree[rt];
    push_down(rt,l,r);
    int mid = (l + r) >> 1;
    ll res = 0;
    if(start <= mid) 
        res += rangeQuery(rt << 1,l,mid,start,end);
    if(end >= mid + 1) 
        res += rangeQuery(rt << 1|1,mid + 1,r,start,end);
    return res;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n ; i ++) 
        scanf("%lld",&A[i]);
    build(1,1,n);
    for(int i = 1; i <= m ; i ++)
    {
        char ch;
        cin >> ch;
        if(ch == 'Q')
        {
            int start,end;
            ll delta;
            scanf("%d %d",&start,&end);
            printf("%lld\n",rangeQuery(1,1,n,start,end));
        }else
        {
            int start,end;
            ll delta;
            scanf("%d %d %lld",&start,&end,&delta);
            updateRange(1,1,n,start,end,delta);
        }
    }
    return 0;
}


// 作者：T-SHLoRk
// 链接：https://www.acwing.com/blog/content/514/
// 来源：AcWing
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。