#include<bits/stdc++.h>
#define int long long

using namespace std;

int n;
int a[100];

void solve()
{
    int cnt1  = 0;
    int cnt2 = 0;
    int max1,max2;
    cin >> n;
    for(int i = 0; i<n;++i)
    {
        cin >> a[i];
    }
    if(n == 1)
    {
        cout << a[0] + 1 << endl;
        return;
    }
    max1 = a[0];
    max2 = a[1];
    for(int i = 0; i<n; i += 2)
    {
        max1 = max(max1,a[i]);
        cnt1++;
    }
    for(int i = 1; i<n; i += 2)
    {
        max2 = max(max2,a[i]);
        cnt2++;
    }
    cout << max(max1 + cnt1, max2 + cnt2) << endl;
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