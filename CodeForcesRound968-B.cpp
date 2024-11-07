#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e5 + 10;

int a[maxn],n;

void solve()
{
    cin >> n;
    for(int i = 0;i<n;++i) cin >> a[i];
    sort(a,a+n);
    cout<<a[n/2]<<endl;
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