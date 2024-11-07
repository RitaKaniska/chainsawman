#include<bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9 + 7;

int sqr(int a)
{
    return a * a;
}

int binpow(int a,int b,int m)
{
    if(b == 0) return 1;
    if(b == 1) return a;
    if(b % 2 == 0)
    {
        return sqr(binpow(a,b/2,m)) % m;
    }
    if(b % 2 == 1)
    {
        return (((sqr(binpow(a,b/2,m)) % m) * a ) % m);
    }
}

void solve()
{
    int a,b,c;
    cin >> a >> b >> c;
    int k = binpow(b,c,mod - 1);
    int ans = binpow(a,k,mod);
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