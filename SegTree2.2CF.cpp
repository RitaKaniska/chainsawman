#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2e5 + 10;

int n,q;
int a[maxn];
int st[4 * maxn];

void build(int id, int l, int r)
{
    if(l == r)
    {
        st[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = st[2 * id] + st[2 * id + 1]; 
}

void update(int id,int l,int r,int pos)
{
    if(pos < l || pos > r)
    {
        return;
    }
    if(l == r)
    {
        st[id] ^= 1;
        return;
    }
    int mid = l + r >> 1;
    update(2 * id, l, mid, pos);
    update(2 * id + 1, mid + 1, r, pos);
    st[id] = st[2 * id] + st[2 * id + 1];
}

int calc(int id, int l,int r, int sum)
{
    if(l == r)
    {
        return l;
    }
    int mid = l + r >> 1;
    if(st[2 * id] >= sum)
    {
        return calc(2 * id, l, mid, sum);
    }
    else
    {
        return calc(2 * id + 1, mid + 1, r, sum - st[2 * id]);
    }
}

void solve()
{
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    build(1,1,n);
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        if(a == 1)
        {
            update(1,1,n,b + 1);
        }
        else cout << calc(1,1,n,b + 1) - 1 << endl;
    }
}

signed main()
{
    solve();
}