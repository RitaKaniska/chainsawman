#include<bits/stdc++.h>
#define int long long 

using namespace std;

const int maxn = 2e5 + 10;
int n,a[maxn];

void solve()
{
    cin >> n;
    for(int i = 0;i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a,a + n);
    int ans = 0;
    for(int i = 0; i < n - 1; ++i)
    {
        if((a[i] + a[i + 1]) > a[n - 1])
        {
            ans = i;
            break;
        }
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