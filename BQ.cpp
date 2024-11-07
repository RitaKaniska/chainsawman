#include<bits/stdc++.h>
#define int long long 

using namespace std;


const int maxn = 2e5 + 10;
int n,a[maxn];

bool isInP(int a[],int n)
{
    int g = 0;
    for(int i = 0; i < n; ++i) g ^= a[i];
    return (g == 0);
}

void solve()
{
    cin >> n;
    for(int i = 0;i < n; ++i) cin >> a[i];
    if(isInP(a,n) == false) cout <<"first" << endl;
    else cout << "second" << endl;
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