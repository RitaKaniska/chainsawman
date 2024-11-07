#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 510;
const int inf = 1e18 + 10;

vector<pair<int,int>> adj[maxn];
int n,m,q;
int dis[maxn][maxn];


void solve()
{
    cin >> n >> m >> q;
    int a,b,c;
    for(int i = 1; i <= n; ++i)
    {
        for(int  j = 1; j <= n; ++j)
        {
            if(i == j) dis[i][j] = dis[j][i] = 0;
            else dis[i][j] = inf;
        }
    }
    for(int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        dis[a][b] = min(dis[a][b],c);
        dis[b][a] = min(dis[b][a],c);
    }
    for(int k = 1; k <= n;++k)
    {
        for(int j = 1; j <= n; ++j)
        {
            for(int i = 1; i <= n; ++i)
            {
                if(dis[i][j] > dis[i][k] + dis[k][j]) dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
    }

    while(q--)
    {
        cin >> a >> b;
        if(dis[a][b] == inf) cout << -1 << endl;
        else cout << dis[a][b] << endl;
    }
}

signed main()
{
    solve();
}