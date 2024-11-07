#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1010;

int n,m,a[maxn][maxn];

void solve()
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }
    int Alice = 0, Bob = 0;
    Alice += a[0][0];
    Bob += a[0][m-1];
    for(int i = 1; i < n; ++i)
    {
        int maxvalue = 0;
        int maxindex = 0;
        int maxindex2 = 0;
        for(int j = 0; j < m; ++j)
        {
            if(a[i][j] >= maxvalue)
            {
                maxvalue = max(a[i][j],maxvalue);
                maxindex = j;
            }
        }
        maxvalue = 0;
        for(int j = 0; j < m; ++j)
        {
            if(j == maxindex) continue;
            if(a[i][j] >= maxvalue)
            {
                maxvalue = max(a[i][j],maxvalue);
                maxindex2 = j;
            }
        }
        if(maxvalue == 0)
        {
            if((a[i][maxindex] + Bob) * Alice >= (a[i][maxindex] + Alice) * Bob)
            {
                Bob += a[i][maxindex];
            }
            else Alice += a[i][maxindex];
        }
        else
        {
            if(maxindex > maxindex2)
            {
                Bob += a[i][maxindex];
                Alice += a[i][maxindex2];
            }
            else
            {
                Bob += a[i][maxindex2];
                Alice += a[i][maxindex];
            }
        }
    }
    int ans = Alice * Bob;
    cout << ans << endl;
}

signed main()
{
    solve();
}