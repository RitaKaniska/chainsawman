#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
int n,m;
vector<pair<int,int>> adj[maxn];
vector<int> dis;
int minj[maxn];
int maxj[maxn];
int cnt[maxn];
//int trace[maxn];

void dijkstra(int i)
{
    cin >> n >> m;
    while(m--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    dis.resize(n + 1, inf);
    vector<bool> P(n + 1,0);
    cnt[i] = 1;
    //for(int i = 1; i <= n; ++i) minj[i] = inf;
    dis[i] = 0;
    priority_queue <pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    pq.push({0,i});
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
            if(dis[e] == dis[x] + w)
            {
                cnt[e] = (cnt[e] + cnt[x]) % mod;
                minj[e] = min(minj[e] , minj[x] + 1);
                maxj[e] = max(maxj[e] , maxj[x] + 1);
                //cout << cnt[e] << endl;
            }
            if(dis[e] > dis[x] + w)
            {
                dis[e] = dis[x] + w;
                minj[e] = minj[x] + 1;
                maxj[e] = maxj[x] + 1;
                cnt[e] = cnt[x];
                //cout << cnt[e] << endl;
                pq.push({dis[e],e});
            }
        }
    }
    cout << dis[n] << " " << cnt[n] << " " << minj[n] << " " << maxj[n] << endl;
}

signed main()
{
    dijkstra(1);
}