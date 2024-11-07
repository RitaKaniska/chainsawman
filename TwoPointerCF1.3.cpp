#include<bits/stdc++.h>
#define int long long

using namespace std;
const int maxn = 2e5 + 10;
int n,m;
int a[maxn],b[maxn];

void solve()
{
    cin >> n >> m;
    for(int i = 0; i < n ; ++i) cin >> a[i];
    for(int i = 0; i < m ; ++i) cin >> b[i];
    map<int,int> a1,b1;
    for(int i = 0; i < n ; ++i)
    {
        a1[a[i]]++;
    }
    for(int i = 0; i < m ; ++i)
    {
        b1[b[i]]++;
    }
    vector<pair<int,int>> a2,b2;
    for(auto x : a1)
    {
        a2.push_back({x.first,x.second});
    }
    for(auto x : b1)
    {
        b2.push_back({x.first,x.second});
    }
    int ptr1 = 0,ptr2 = 0;
    int ans = 0;
    int n1 = a2.size(), m1 = b2.size();
    while(ptr1 != n1 || ptr2 != m1)
    {
        if(a2[ptr1].first > b2[ptr2].first && ptr2 < m1)
        {
            ptr2++;
        }
        else if(a2[ptr1].first < b2[ptr2].first && ptr1 < n1)
        {
            ptr1++;
        }
        if(a2[ptr1].first == b2[ptr2].first)
        {
            ans += a2[ptr1].second * b2[ptr2].second;
            if(ptr1 < n1)ptr1++;
            if(ptr2 < m1)ptr2++;
        }
        if(ptr1 == n1 && a2[ptr1] != b2[ptr2]) break;
        if(ptr2 == m1 && a2[ptr1] != b2[ptr2]) break;
    }
    cout << ans << endl;
}

signed main()
{
    solve();
}