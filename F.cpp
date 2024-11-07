#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2e6 + 10;

int dp[maxn],dp2[maxn];
int a[maxn];
int n;
int logn = 20;

int getbit(int a,int b)
{
    return ((a >> b) & 1LL);    
}

void solve()
{
    cin >> n;
    for(int i = 1;i <= n; ++i)
    {
        cin >> a[i];
        dp[a[i]]++;
        dp2[a[i]]++;
    }
    int mask = (1 << logn) - 1;
    for(int j = 0; j <= logn - 1; j++)
    {
        for(int i = 0; i <= mask; i++)
        {
            if(getbit(i,j)) dp[i] += dp[i ^ (1 << j)];
            else dp2[i] += dp2[i | (1 << j)];
        }
    }
    for(int i = 1;i <= n; ++i)
    {
        cout << dp[a[i]] <<" " << dp2[a[i]] <<" " << n - dp[mask ^ a[i]] <<endl;
    }
}

signed main()
{
    solve();
    
}