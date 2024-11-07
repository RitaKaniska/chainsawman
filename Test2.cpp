#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2e5 + 10;

int n,q;
int a[maxn];
int st[4 * maxn];

bool check(int a,int k)
{
    if(a % k == 0) return true;
    if(k < 10)
    {
        while(a > 0)
        {
            if(a % 10 == k) return true;
            a /= 10;
        }
    }
    return false;
}

void build(int id,int l,int r)
{
    if(l == r)
    {
        //if(check(a[l],l) == true) st[id] = 2 * a[l];
        st[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(2*id,l,mid);
    build(2*id + 1,mid+1,r);
    st[id] = st[2*id] + st[2*id + 1];
}

void update(int id,int l,int r,int pos, int val)
{
    if(pos < l || pos > r) return;
    if(l == r)
    {
        st[id] = val;
        return;
    }
    int mid = l + r >> 1;
    update(2 * id,l,mid,pos,val);
    update(2*id + 1,mid + 1,r,pos,val);
    st[id] = st[2 * id] + st[2*id + 1];
}

int calc(int id,int l,int r,int u,int v)
{
    if(r < u || l > v) return 0;
    if(l >= u && r <= v)
    {
        return st[id];
    }
    int mid = l + r >> 1;
    int cal1 = calc(2*id,l,mid,u,v);
    int cal2 = calc(2*id + 1,mid + 1,r,u,v);
    return cal1 + cal2;
}

void solve()
{
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    build(1,1,n);
    while(q--)
    {
        int query,b,c,d;
        cin >> query;
        if(query == 1)
        {
            cin >> b >> c;
            //if(check(c,b) == true) d = 2 * c;
            d = c;
            update(1,1,n,b,d);
        }
        else
        {
            cin >> b >> c >> d;
            cout << calc(1,1,n,b,c) << endl;
        }
    }
}

signed main()
{
    solve();
}