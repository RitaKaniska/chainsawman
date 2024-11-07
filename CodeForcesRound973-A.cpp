#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    double a,b,c;
    cin >> a >> b >> c;
    int ans = ceil(a / min(b,c));
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