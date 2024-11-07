#include<bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9 + 7;

int sqr(int a){
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
        return ((sqr(binpow(a,b/2)) % mod ) * a ) % mod;
    }
}

void solve()
{
    int a,b;
    cin >> a >> b;
    cout << binpow(a,b) << '\n';
}

signed main()
{
    int t;
    cin >> t;
    while(t --)
    {
        solve();
    }
}