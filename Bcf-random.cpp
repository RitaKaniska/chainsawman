#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2e5 +  10;

int n,m,a[maxn];


void solve()
{
    cin >> n >> m;
    int x = INT_MIN;
    int index = 1;
    for(int i = 1;i<=n;++i)
    {
        cin >> a[i];
        if(a[i] > x)
        {
            x = a[i];
            index = i;
        }
    }
    while(m--)
    {
        char s;
        int a,b;
        cin >> s >> a >> b;
        if(a <= index && b >= index)
        {
            if(s == '+') x += 1;
            else x -= 1;
        }
        cout << x << ' ';
    }
    cout<<endl;
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