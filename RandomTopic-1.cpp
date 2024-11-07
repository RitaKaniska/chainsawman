#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int n,k;
    int a,b;
    cin >> n >> k;
    for(int i = 0;i < n; ++i)
    {
        cin >> a >> b;
    }
    if(k < 4) cout << "YES" << endl;
    else if(k == 4)
    {
        if(n % 4 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else cout << "NO" << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}