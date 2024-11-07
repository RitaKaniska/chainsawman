#pragma GCC optimize("O3")
#pragma GCC target("avx2,bmi2,popcnt")
#include<bits/stdc++.h>
#define int long long

using namespace std;

const int inf = 1e9 + 7;

string t;
int test;

void solve()
{
    string k;
    cin >> k;
    vector<int> v;
    int ans = inf;
    for(int i = 0; i < t.size(); ++i)
    {
        if(t[i] == k[0]) v.push_back(i);
    }
    for(int i = 0; i < v.size(); ++i)
    {
        int cnt = 0;
        int start = v[i];
        int ptr2 = 0;
        while(ptr2 < k.size() && start < t.size())
        {
            if(k[ptr2] == t[start])
            {
                ptr2++;
                start++;
            }
            else
            {
                start++;
                cnt++;
            }
        }
        if(ptr2 < k.size()) cnt = inf;
        ans = min(ans,cnt);
    }
    if(ans == inf) ans = -1;
    cout << ans << endl;
}

signed main()
{
    cin >> t;
    cin >> test;
    while(test--)
    {
        solve();
    }
}