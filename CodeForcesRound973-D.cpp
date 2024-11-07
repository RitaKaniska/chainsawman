#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2e5 + 10;
int n,a[maxn];

void solve()
{
    cin >> n;
    int maxindex = 0,maxvalue;
    for(int i = 0;i<n;++i) cin >> a[i];
    maxvalue = a[0];
    for(int i = 0;i < n ;++ i)
    {
        if(maxvalue < a[i])
        {
            maxvalue = a[i];
            maxindex = i;
        }
    }
    if(n == 1)
    {
        cout <<0<<endl;
        return;
    }
    int minbefore = a[0];
    for(int  i = 0; i <= maxindex - 1; ++i)
    {
        minbefore = min(minbefore,a[i]);
    }
    int sum = 0;
    int cnt = 0;
    for(int i = maxindex; i < n; ++i)
    {
        sum += a[i];
        cnt++;
    }
    if(sum % cnt  == 0) sum = sum / cnt;
    else sum = (sum / cnt) + 1;
    int ans = max(1LL,sum - minbefore);
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