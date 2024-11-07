#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,a;
        int ans = 0;
        cin >> n;
        for(int i = 0; i < n; ++i)
        {
            cin >> a;
            if(i % 2) ans ^= a;
        }
        if(ans) cout << "first" << endl;
        else cout << "second" << endl;
    }
}