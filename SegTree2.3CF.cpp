#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2e5 + 10;

int n,q;
int a[maxn];
int st[4 * maxn];

void build(int id,int l,int r)
{
    if(l == r)
    {
        st[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(2 *id,l,mid);
    build(2 *id + 1, mid + 1, r);
    st[id] = max(st[2 *id] , st[2 *id + 1]);
}

void update(int id,int l,int r,int pos,int val)
{
    if(pos < l || pos > r)
    {
        return;
    }
    if(l == r)
    {
        st[id] = val;
        return;
    }
    int mid = l + r >> 1;
    update(2 * id, l, mid, pos, val);
    update(2 * id + 1, mid + 1, r, pos, val);
    st[id] = max(st[2 * id],st[2 * id + 1]);
}

int calc(int id,int l,int r,int val)
{
    if(l == r)
    {
        if(st[id] >= val) return l;
        else return -1;
    }
    int mid = l + r >> 1;
    if(st[2 * id] >= val) return calc(2 * id, l, mid, val);
    else return calc(2 * id + 1, mid + 1, r, val);
}

void solve()
{
    cin >> n >> q;
    for(int  i = 1; i <= n; ++i) cin >> a[i];
    build(1,1,n);
    while(q--)
    {
        int b,c,d;
        cin >> b;
        if(b == 1)
        {
            cin >> c >> d;
            update(1,1,n,c + 1,d);
        }
        else
        {
            cin >> c;
            int ans = calc(1,1,n,c);
            if(ans != -1) ans--;
            cout << ans << endl;
        }
    }
}

signed main()
{
    solve();
}