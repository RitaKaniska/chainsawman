#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e5 + 10;
int n,a[maxn];
int g[maxn];

int mex(vector<int> current)
{
    sort(current.begin(),current.end());
    set<int> s;
    for(int i = 0; i < current.size(); ++i) s.insert(current[i]);
    for(int i = 0; i <= current.size();++i)
    {
        if(s.find(i) == s.end()) return i;
    }
    return 0;
}

void solve()
{
    cin >> n;
    for(int i = 0 ;i < n ;++i) cin >> a[i];
    int ans = 0;
    for(int i = 0; i < n; ++i) ans ^= g[a[i]];
    if(ans == 0) cout << "2" <<endl;
    else cout << "1" <<endl;
}

signed main()
{
    g[1] = 0;
    g[0] = 0;
    for(int i = 2; i <= maxn - 1;++i)
    {
        vector<int> current;
        for(int j = 1; j * j <= i; ++j)
        {
            if(i % j == 0)
            {
                if (j != 1){
                    if(j % 2 == 0) current.push_back(0);
                    if(j % 2 == 1) current.push_back(g[i / j]);
                }

                if (i / j != 1){
                    if((i / j) % 2 == 0) current.push_back(0);
                    if((i / j) % 2 == 1) current.push_back(g[j]);
                }
            }
        }
        g[i] = mex(current);
        //cout << i << ":" << g[i] << '\n';
    }
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}