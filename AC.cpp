#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1010;
const int inf = 1e18 + 7;

int n,m;
vector<int> adj[maxn];
int c[maxn][maxn], f[maxn][maxn], maxflow = 0;
int trace[maxn];

void bfs()
{
    fill(trace, trace + n + 1, 0);
    trace[1] = -1;

    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto x : adj[u])
        {
            if(trace[x]) continue;
            if(f[u][x] - c[u][x] == 0) continue;

            trace[x] = u;
            q.push(x);
        }
    }
}

void inflow()
{
    int delta = inf;
    int v = n;
    while(v != 1)
    {
        int u = trace[v];
        delta = min(delta,c[u][v] - f[u][v]);
        v = u;
    }
    maxflow += delta;
    v = n;
    while(v != 1)
    {
        int u = trace[v];
        f[u][v] += delta;
        f[v][u] -= delta;
        v = u;
    }
}

signed main()
{
    cin >> n >> m;
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        int k; cin >> k;
        c[a][b] += k;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    maxflow = 0;

    do
    {
        bfs();
        if(trace[n]) inflow();
    } while(trace[n]);

    cout << maxflow << endl;
}