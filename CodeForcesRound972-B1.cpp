#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int m,n,q;
    int b1,b2,a;
    cin >> m >> n >> q;
    cin >>b1 >> b2 >> a;
    int ans;
    if(a > b1 && a > b2)
    {
        ans = m - max(b1,b2);
    }
    else if(a < b1 && a < b2)
    {
        ans = min(b1,b2) - 1;
    }
    else
    {
        ans = abs((b1-b2) / 2);
    }
    cout << ans << endl;
}

signed main()
{
    int t;
    cin >> t;
    while(t -- )
    {
        solve();
    }
}