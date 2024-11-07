#include<bits/stdc++.h>
#define int long long 

using namespace std;

const int maxn = 2e5 + 10;

int n,m;
vector<int> adj[maxn];
int up[maxn][18],h[maxn];
int dp[maxn];
int diff[maxn];
int ans[maxn];

void input()
{
    cin >> n >> m;
    for(int i = 2; i <= n; ++i)
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

        for(int i = 1; i <= 17; ++i) up[x][i] = up[up[x][i - 1]][i - 1];
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
    for(int i = t; i >= 0; i--)
    {
        if(up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int dpontree(int v)
{
    int answer = 0;
    for(auto x : adj[v])
    {
        if(up[v][0] == x) continue;
        answer += dpontree(x);
        //cout << answer << endl;
    }
    ans[v] = answer +  diff[v];
    return ans[v];
}

void solve()
{
    input();
    preprocess(1);
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        int c = lca(a,b);
        diff[a] += 1;
        diff[b] += 1;
        diff[c] -= 1;
        diff[up[c][0]] -= 1;
    }
    int k = dpontree(1);
    for(int i = 1; i <= n; ++i)
    {
        cout << ans[i] <<' ';
    }
    cout << endl;
}

signed main()
{
    solve();
}