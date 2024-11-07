#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s[n + 1];
    for(int i = 1;i <=n;++i) cin >> s[i];
    vector<int> ans;
    for(int i = n;i>=1;i--)
    {
        for(int j = 0;j<4;++j)
        {
            if(s[i][j] == '#')
            {
                ans.push_back(j + 1);
            }
        }
    }
    for(int i = 0;i < ans.size();++i)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
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
