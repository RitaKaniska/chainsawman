#include<bits/stdc++.h>
#define int long long

using namespace std;

int n,k;

void solve()
{
    cin >> n >> k;
    if(n == 1)
    {
        cout << 1 << endl << 1 << endl;
        return;
    }
    if(k == 1 || k == n)
    {
        cout << -1 << endl;
        return;
    } 
    if(k % 2 == 0)
    {
        cout << 3 << endl;
        cout << 1 << ' ' << k << ' ' << k + 1 << endl;
        return;
    }
    else
    {
        cout << 5 << endl;
        cout << 1 << ' ' << k - 1 <<' ' << k << ' ' << k + 1 << ' ' << k + 2 << endl;
        return;
    }
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