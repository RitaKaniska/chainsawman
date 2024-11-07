#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e5 + 10;

int n,m;
vector<int> adj[maxn];
int t[maxn],l[maxn];
int cnt;
vector<int> ans;

void dfs(int x,int p)
{
    t[x] = l[x] = ++cnt;
    int c = (x != p);
    for(int i : adj[x])
    {
        if(i == p) continue;
        if(t[i] == 0)
        {
            dfs(i,x);
            l[x] = min(l[i],l[x]);
            if(l[i] >= t[x]) ++c;
        }
        else l[x] = min(t[i],l[x]);
    }
    if(c >= 2)
    {
        ans.push_back(x);
    }
}

signed main()
{
    cin >> n >> m;
    int a,b;
    while(m--)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i)
    {
        if(t[i] == 0) dfs(i,i);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}