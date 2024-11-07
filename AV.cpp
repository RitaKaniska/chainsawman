#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2e5 + 10;

int n,q;
vector<int> adj[maxn];
int h[maxn];
int up[maxn][18];
int par[maxn];

void input()
{
    cin >> n >> q;
    for(int i = 0 ; i < n - 1; ++i)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void preprocess(int v)
{
    for(auto x : adj[v])
    {
        if(x == up[v][0]) continue;
        h[x] = h[v] + 1;
        up[x][0] = v;

        for(int i = 1; i <= 17; ++i)
        {
            up[x][i] = up[up[x][i - 1]][i - 1];
        }
        preprocess(x);
    }
}

int lca(int a, int b)
{
    if(a != b)
    {
        if(h[a] < h[b]) swap(a,b);
        int k = h[a] - h[b];
        for(int i = 0; (1 << i) <= k; ++i)
        {
            if(k >> i & 1) a = up[a][i];
        }
    }
    if(a == b) return a;
    int t = __lg(h[a]);
    for(int i = t; i >= 0; --i)
    {
        if(up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

signed main()
{
    input();
    preprocess(1);
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        int c = lca(a,b);
        int ans = abs(h[a] - h[c]) + abs(h[b] - h[c]);
        cout << ans << endl;
    }
}