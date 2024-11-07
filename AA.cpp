#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2e5 + 10;
const int inf = 1e18 + 7;

int n,m;
vector<pair<int,int>> adj[maxn];
vector<int> dis;

void dijkstra()
{
    cin >> n >> m;
    int a,b,c;
    while(m--)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    dis.resize(n+1,inf);
    vector<bool> P(n + 1, 0);

    dis[1] = 0;
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    pq.push({0,1});

    while(!pq.empty())
    {
        int x = pq.top().second;
        pq.pop();
        if(P[x] == true) continue;
        P[x] = true;

        for(auto u : adj[x])
        {
            int e = u.first;
            int w = u.second;
            if(dis[e] > dis[x] + w)
            {
                dis[e] = dis[x] + w;
                pq.push({dis[e],e});
            }
        }
    }

    for(int i = 1 ; i <= n; ++i)
    {
        cout << dis[i] <<" ";
    }
}

signed main()
{
    dijkstra();
}