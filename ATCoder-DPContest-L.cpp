#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 3001;

int n,a[maxn];
int dp[maxn][maxn];

void solve()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        dp[i][i] = a[i];
    }
    for(int i = n - 1;i >= 0; i--)
    {
        for(int j = i + 1;j < n; ++j)
        {
            dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
        }
    }
    cout << dp[0][n - 1] << endl;
}

signed main()
{
    solve();
}