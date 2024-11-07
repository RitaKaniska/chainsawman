#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn  = 2e5 + 10;
int a[maxn];

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0;i<n;++i)
    {
        cin >> a[i];
        if(i == n - 2) ans -= a[i];
        else ans += a[i];
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

