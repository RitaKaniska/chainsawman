#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;

int n,x,dp[maxn],a[110];

signed main()
{
    cin >> n >> x;
    for(int  i = 0; i < n;++i) cin >> a[i];
    for(int i = 0;i <= x;++i) dp[i] = 0;
    dp[0] = 1;
    for(int i = 0; i <= x;++i)
    {
        for(int j = 0 ;j < n;++j)
        {
            if(a[j] <= i) dp[i] = (dp[i] + dp[i-a[j]]) % mod;
        }
    }
    cout << dp[x] << endl;
}