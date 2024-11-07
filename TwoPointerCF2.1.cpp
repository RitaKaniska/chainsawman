#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e5 + 10;

int n,s;
int a[maxn];

void solve()
{
    cin >> n >> s;
    for(int i = 0; i < n; ++i) cin >> a[i];
    int l = 0, r = 0;
    int ans = 0;
    int curr = 1;
    int currsum = 0;
    while(r < n)
    {
        currsum += a[r];
        while(currsum > s)
        {
            currsum -= a[l];
            l++;
        }
        ans = max(ans,r - l + 1);
        r++;
    }
    cout << ans << endl;
}

signed main()
{
    solve();
}