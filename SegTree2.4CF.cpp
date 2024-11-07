#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#pragma GCC optimize(" unroll-loops")
#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2e5 + 10;
const int inf = 1e6 + 10;

int n,m;
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
    build(2 * id, l ,mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = max(st[2 * id],st[2 * id + 1]);
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
    update(2 * id,l,mid,pos,val);
    update(2 * id + 1,mid + 1,r,pos,val);
    st[id] = max(st[2 * id],st[2 * id + 1]);
} 

int calc(int id,int l,int r,int pos,int val)
{
    if(r < pos || st[id] < val) return -inf;
    if(l == r)
    {
        return l;
    }
    int mid = l + r >> 1;
    int cal1 = calc(2 * id,l,mid,pos,val);
    int cal2 = calc(2 * id + 1,mid + 1,r,pos,val);
    if(cal1 != -inf) return cal1;
    else return cal2;
}


void solve()
{
    cin >> n >> m;
    for(int i = 1; i <=n; ++i) cin >> a[i];
    build(1,1,n);
    int b,c,d;
    while(m--)
    {
        cin >> b >> c >> d;
        if(b == 1)
        {
            update(1,1,n,c + 1,d);
        }
        else
        {
            int ans = calc(1,1,n,d + 1,c);
            if(ans == -inf)
            {
                cout << - 1 << endl;
            }
            else cout << ans - 1 << endl;
        }
    }
}

signed main()
{
    solve();
}