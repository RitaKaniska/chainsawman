#include<bits/stdc++.h>
#define int long long

using  namespace std;

signed main()
{
    int t;
    cin >> t;
    while(t -- )
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(s[0] == s[s.size() - 1]) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}