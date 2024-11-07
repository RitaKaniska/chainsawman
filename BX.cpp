#include<bits/stdc++.h>
#define int long long 

using namespace std;

const int maxn = 1010;

int n;
pair<int,int> a[maxn];

void solve()
{
    cin >> n;
    for(int i = 0 ; i < n; ++i)
    {
        cin >> a[i].first;
        cin >> a[i].second;
    }

    int ans = 0;
    for(int i = 0; i < n - 1; ++i)
    {
        ans += (a[i].first * a[i + 1].second - a[i].second * a[i + 1].first);
    }
    ans += (a[n-1].first * a[0].second - a[n-1].second * a[0].first);
    cout << abs(ans) << endl;
}

signed main()
{
    solve();
}