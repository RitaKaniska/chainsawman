#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;

int n,x,dp[maxn],a[100];

void solve()
{
    cin >> n;
    cin >> x;
    for(int i = 0;i < n; ++i) cin >> a[i];
    dp[0] = 1;
    for(int i = 1;i<=x;++i) dp[i] = 0;
    for(int j = 0;j < n; ++j)
    {
        for(int i = 1; i <= x; ++ i)
        {
            if(i >= a[j]) dp[i] = (dp[i - a[j]] + dp[i] ) % mod;
        }
    }
    cout << dp[x] << endl;
}

signed main()
{
    solve();
}