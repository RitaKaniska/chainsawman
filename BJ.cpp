#include<bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 2e6 + 10;
int n,m;
int lt[maxn];

int sqr(int a)
{
    return a * a;
}

int binpow(int a,int b)
{
    if(b == 0)
    {
        return 1;
    }
    if(b == 1)
    {
        return a;
    }
    if(b % 2 == 0)
    {
        return sqr(binpow(a,b/2)) % mod;
    }
    if(b % 2 == 1)
    {
        return ((sqr(binpow(a,b/2)) % mod) * a) % mod;
    }
}

signed main()
{
    int t = 1;
    lt[0] = 1;
    for(int i = 1; i <= 2e6 +1;++i) lt[i] = (lt[i-1] * i) % mod;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        int n1 = m + n - 1;
        int m1 = n - 1;

        int k1 = binpow(lt[n-1],mod - 2);
        int k2 = binpow(lt[m], mod -2);

        int ans = (lt[n1] * k1) % mod;
        ans = (ans * k2) % mod;

        cout << ans << endl;
    }
}