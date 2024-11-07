#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
int lt[maxn];

int sqr(int a)
{
    return a * a;
}

int binpow(int a,int b)
{
    if(b == 0) return 1;
    if(b == 1) return a;
    if(b % 2 == 0)
    {
        return sqr(binpow(a,b/2)) % mod;
    }
    if(b % 2 == 1)
    {
        return (sqr(binpow(a,b/2)) % mod * a) % mod;
    }
}

signed main()
{
    int t;
    cin >> t;
    lt[0] = 1;
    for(int i = 1; i <= 1e6; ++i)
    {
        lt[i] = (lt[i-1] * i) % mod;
    }

    while(t--)
    {
        int a,b;
        cin >> a >> b;
        int k1 = binpow(lt[b], mod - 2);
        int k2 = binpow(lt[a - b], mod - 2);
        int ans = (lt[a] * k1) % mod;
        ans = (ans * k2) % mod;
        cout << ans << endl;
    }
}