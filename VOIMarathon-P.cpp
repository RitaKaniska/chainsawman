#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2e5 + 10;

vector<int> adj[maxn];
int n,m;
int l[maxn],t[maxn],cnt;
int ans = 0;
vector<int> v;

void dfs(int x,int p)
{
    l[x] = t[x] = ++cnt;
    int c = x != p;
    for(int k : adj[x])
    {
        if(k == p) continue;
        if(t[k] == 0)
        {
            dfs(k,x);
            l[x] = min(l[k],l[x]);

            if(l[k] >= t[x]) c++;
        }
        else l[x] = min(l[x],t[k]);

    }
    if(c >= 2)
    {
        ans++;
        v.push_back(x);
    }
}

signed main()
{
    cin >> n >> m;
    int a,b;
    for(int i = 0;i < m; ++i)
    {
        cin >> a >> b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }
    for(int i = 1; i <= n; ++i)
    {
        if(l[i] == 0) dfs(i,i);
    }
    cout << v.size() << endl;
    for(int i = 0;i < v.size(); ++i)
    {
        cout<< v[i] <<' ';
    }
    cout<<endl;
}