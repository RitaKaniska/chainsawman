#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e5 + 10;

int n,m;
vector<int> adj[maxn];
int t[maxn],l[maxn];
int cnt;
vector<pair<int,int>> v1;

void dfs(int x,int p)
{
    t[x] = l[x] = ++cnt;
    for(int i : adj[x])
    {
        if(i == p) continue;
        if(t[i] == 0)
        {
            dfs(i,x);
            l[x] = min(l[x],l[i]);
            if(l[i] > t[x])
            {
                v1.push_back({i,x});
            }
        }
        else l[x] = min(l[x],t[i]);
    }
}

signed main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) adj[i].clear();
    for(int i = 1; i <= m;++i)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i)
    {
        if(t[i] == 0) dfs(i,i);
    }
    cout << v1.size() << endl;
    for(int i = 0; i < v1.size();++i)
    {
        cout << v1[i].first << " " << v1[i].second << endl;
    }
}