#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;

int n,x,a[maxn],dp[maxn];

void solve()
{
    cin >> n >> x;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0;i <= x; ++i) dp[i] = 0;
    dp[0] = 1;
    for(int j = 0; j < n; ++j)
    {
        for(int i = 0; i <= x; ++i)
        {
            if(i >= a[j]) dp[i] = (dp[i] + dp[i - a[j]]) % mod;
        }
    }
    cout << dp[x] << endl;
}

signed main()
{
    solve();
}