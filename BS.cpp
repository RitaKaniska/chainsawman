#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e6 + 10;
int g[maxn];

int mex(vector<int> current)
{
    sort(current.begin(),current.end());
    set<int> s;
    for(int i = 0; i < current.size(); ++i) s.insert(current[i]);
    // for(int i : s) cout << i << " ";
    // cout << '\n';
    for(int i = 0; i <= current.size(); ++i)
    {
        if(s.find(i) == s.end()) return i;
    }
}

void solve()
{
    int n;
    cin >> n;
    if(n > 5000) cout <<"first" <<endl;
    else
    {
        if(g[n] == 0) cout << "second" <<endl;
        else cout << "first" <<endl;
    }
}

signed main()
{
    int t;
    cin >> t;
    g[1] = 0;
    for(int i = 2; i <= 5000; ++i)
    {
        vector<int> current;
        for(int j = 1; j <= i / 2; ++j)
        {
            if(2 * j != i) current.push_back(g[j] ^ g[i - j]);
        }
        g[i] = mex(current);
    }
    while(t--)
    {
        solve();
    }
}