#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2e5 + 10;

int n,q;
int par[maxn];
int up[maxn][18];
int h[maxn];
vector<int> adj[maxn];

void input()
{
    cin >> n >> q;
    for(int i = 2; i <= n; ++i)
    {
        cin >> par[i];
        adj[par[i]].push_back(i);
        adj[i].push_back(par[i]);
        up[i][0] = par[i];
    }
}

void preprocess(int v)
{
    for(auto x : adj[v])
    {
        if(x == up[v][0]) continue;
        h[x] = h[v] + 1;

        //up[x][0] = v;

        for(int j = 1; j <= 17; j++)
        {
            up[x][j] = up[up[x][j - 1]][j - 1];
        }
        //cout << up[x][1] << endl;
        preprocess(x);
    }
}

int lca(int a,int b)
{
    if(a != b)
    {
        if(h[a] < h[b]) swap(a,b);

        int k = h[a] - h[b];
        for(int j = 0; (1 << j) <= k; ++j)
        {
            if(k >> j & 1) a = up[a][j];
        }
    }
    if(a == b) return a;
    int t = __lg(h[a]);
    for(int j = t; j >= 0; j--)
    {
        if(up[a][j] != up[b][j])
        {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

void solve()
{
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        cout << lca(a,b) << endl;
    }
}

signed main()
{
    //cout << lca(1,1) << endl;
    input();
    h[1] = 0;
    //for(int i = 0; i < adj[1].size();++i) cout << adj[1][i]<< ' ';
    //cout << endl;
    preprocess(1);
    solve();
}