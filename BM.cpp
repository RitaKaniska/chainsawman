#include<bits/stdc++.h>
#define int long long

using namespace std;


const int maxk = 20;
int n,k,a[maxk];

void solve()
{
    cin >> n >> k;
    for(int i = 0; i < n; ++i) cin >> a[i];
    int cnt = n;
    for(int mask = 0; mask < (1 << k); ++mask)
    {
        bool odd = (__builtin_popcount(mask)&1);
        int prod = 1;
        double LHS = 0.0;
        for(int i = 0;i < k; ++i)
        {
            if(mask & (1 << i))
            {
                prod *= a[i];
            }
        }
        cnt += (odd ? 1 : -1) * (n/prod);
    }
    cout << cnt <<endl;
}

signed main()
{
    solve();
}