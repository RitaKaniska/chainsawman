#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2e5 + 10;

int n,m;
vector<int> adj[maxn];
int val[maxn];
int par[maxn],depth[maxn],sz[maxn],pos[maxn],arr[maxn];
int ChainID[maxn],ChainHead[maxn];
int CurChain,Curpos;

void dfs(int s,int p = -1)
{
    sz[s] = 1;
    for(auto u : adj[s])
    {
        if(u == p) continue;
        depth[u] = depth[s] + 1;
        par[u] = s;
        dfs(u,s);
        sz[s] += sz[u];
    }
}

void HLD(int s,int p = -1)
{
    if(!ChainHead[CurChain]) ChainHead[CurChain] = s;
    ChainID[s] = CurChain;
    pos[s] = Curpos;
    arr[Curpos] = s;
    Curpos++;
    int next = 0;
    for(int u : adj[s])
    {
        if(u != p)
        {
            if(next == 0 || sz[next] < sz[u]) next = u;
        }
    }
    if(next) HLD(next, s);
    for(int u : adj[s])
    {
        if(u != p && u != next)
        {
            CurChain++;
            HLD(u,s);   
        }
    }
}

int LCA(int u,int v)
{
    while(ChainID[u] != ChainID[v])
    {
        if(ChainID[u] > ChainID[v])
        {
            u = par[ChainHead[ChainID[u]]];
        }
        else v = par[ChainHead[ChainID[v]]];
    }
    if(depth[u] < depth[v]) return u;
    return v;
}

int st[4 * maxn];

void build(int id,int l,int r)
{
    if(l == r)
    {
        st[id] = val[arr[l]];
        return;
    }
    int mid = l + r >> 1;
    build(2 * id,l,mid);
    build(2 * id + 1,mid + 1,r);
    st[id] = max(st[2 * id], st[2 * id + 1]);
}

void update(int id,int l,int r,int pos,int val)
{
    if(pos < l || pos > r) return;
    if(l == r)
    {
        st[id] = val;
        return;
    }
    int mid = l + r >> 1;
    update(2 * id,l,mid,pos,val);
    update(2 * id + 1,mid + 1,r,pos,val);
    st[id] = max(st[2*id],st[2*id + 1]);
}

void upd(int s,int v)
{
    update(1,1,n,pos[s],v);
}

int calc(int id,int l,int r,int u,int v)
{
    if(r < u || l > v) return 0;
    if(l >= u && r <= v) return st[id];
    int mid = l + r >> 1;
    return max(calc(2 * id,l,mid,u,v) , calc(2 * id + 1,mid + 1,r,u,v));
}

int query(int u,int v)
{
    int lca = LCA(u,v);
    int ans = 0;
    while(ChainID[u] != ChainID[lca])
    {
        ans = max(ans,calc(1,1,n,pos[ChainHead[ChainID[u]]],pos[u]));
        u = par[ChainHead[ChainID[u]]];
    }
    while(ChainID[v] != ChainID[lca])
    {
        ans = max(ans,calc(1,1,n,pos[ChainHead[ChainID[v]]],pos[v]));
        v = par[ChainHead[ChainID[v]]];
    }
    if(depth[u] < depth[v])
    {
        ans = max(ans,calc(1,1,n,pos[u],pos[v]));
    }
    else ans = max(ans,calc(1,1,n,pos[v],pos[u]));
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n; ++i) cin >> val[i];
    int a,b,q;
    for(int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    Curpos = CurChain = 1;
    dfs(1);
    HLD(1);
    build(1,1,n);
    while(m--)
    {
        cin >> q >> a >> b;
        if(q == 1)
        {
            upd(a,b);
        }
        else
        {
            cout << query(a,b) << ' ';
        }
    }
}