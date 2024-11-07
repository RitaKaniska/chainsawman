#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int a,b;
    cin>>a>>b;
    int k = (((b + 1) / 2 - a / 2) / 2);
    cout<< k << endl;
}

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}