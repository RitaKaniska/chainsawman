#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2e5 + 10;

int n,q;
int a[maxn];
int cntq[maxn];
int st[4 * maxn];

void build(int id,int l,int r)
{
    if(l == r)
    {
        st[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(2 * id,l,mid);
    build(2 * id + 1, mid + 1,r);
    st[id] = max(st[2 * id] , st[2 * id + 1]);
}

void update(int id,int l,int r,int i,int val)
{
    if(r < i || l > i) return;
    if(l == r)
    {
        st[id] = val;
        return;
    }
    int mid = l + r >> 1;
    update(2 * id,l,mid,i,val);
    update(2 * id + 1,mid + 1,r,i,val);
    st[id] = max(st[2*id],st[2*id + 1]);
}

int query(int id,int l,int r,int val)
{
    if(l == r)
    {
        if(st[id] < val) return 0;
        update(1,1,n,l,st[id] - val);
        return l;
    }
    int mid = l + r >> 1;
    if(st[2 * id] >= val)
    {
        return query(2*id,l,mid,val);
    }
    else if(st[2*id + 1] >= val)
    {
        return query(2 *id + 1,mid + 1,r,val);
    }
    else return 0;
}

signed main()
{
    cin >> n >> q;
    for(int i = 1 ;i <= n; ++i)
    {
        cin >> a[i];
    }
    build(1,1,n);
    //for(int i = 1; i <= 4 * n; ++i) cout <<st[i] <<endl;
    for(int i = 0 ;i < q; ++i) cin >>cntq[i];
    for(int i = 0; i < q; ++i)
    {
        cout << query(1,1,n,cntq[i]) << endl;
    }
}