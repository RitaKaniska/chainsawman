#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1000;
int n,a[maxn];

void solve()
{
    int cnt1 = 0,cnt0 = 0;
    int a;
    cin >> n;
    for(int i = 0; i < 2  * n; ++i)
    {
        cin >> a;
        if(a == 1) cnt1++;
        else cnt0++;
    }
    int min_ = (cnt1 % 2) ;
    int max_ = min(cnt1,cnt0);
    cout << min_ <<' ' << max_ << endl;
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