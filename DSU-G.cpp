#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2e5 + 10;

struct edge{
    int u,v,c;
};

int n,m;
vector<edge> E;
int parent[maxn],sz[maxn];

void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v)
{
    return parent[v] == v ? v : parent[v] = find_set(parent[v]);
}

void union_set(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a != b)
    {
        if(sz[a] < sz[b]) swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}


signed main()
{
    cin>>n>>m;
    int ans = 0;
    for(int i = 0;i<m;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        E.push_back({a,b,c});
    }
    for(int i = 1;i<=n;++i) make_set(i);
    sort(E.begin(),E.end(),[](edge &x, edge &y)
    {
        return x.c < y.c;
    });
    for(auto e : E)
    {
        if(find_set(e.u) != find_set(e.v))
        {
            union_set(e.u,e.v);
            ans += e.c;
        }
    }
    int k = find_set(1);
    if(sz[k] != n)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else cout<<ans<<endl;
}