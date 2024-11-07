#include<bits/stdc++.h>
#define int long long

using namespace std;

int n,k;
map<int,int> mp;
vector<int> v;

void solve()
{
    cin >> n >> k;
    mp.clear();
    v.clear();
    int a,b;
    for(int i = 0; i < k; ++i)
    {
        cin >> a >> b;
        mp[a] += b;
    }
    for(pair<int,int> x : mp)
    {
        v.push_back(x.second);
    }
    sort(v.begin(),v.end());
    int ans = 0;
    for(int i = v.size() - 1; i >= 0 && i >= v.size() - n; i--)
    {
        ans += v[i];
    }
    cout << ans << endl;
}

signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}