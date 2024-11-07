#include<bits/stdc++.h>
#define int long long

using namespace std;

int n,q;
int val[maxn];
vector<int> adj[maxn];

int par[maxn],depth[maxn],sz[maxn],pos[maxn],arr[maxn];
int ChainID[maxn],ChainHead[maxn];
int CurChain,CurPos;

void dfs(int s,int p = -1)
{
    sz[s] = 1;
    for(int u : adj[s])
    {
        if(u == p) continue;
        par[u] = s;
        depth[s] = depth[u] + 1;
        sz[s] += sz[u];
    }
}

void HLD(int s,int p = -1)
{
    if(!ChainHead[ChainID[s]]){
        ChainHead[ChainID[s]] = s;
    }
    ChainID[s] = CurChain;
    
}

signed main()
{

}