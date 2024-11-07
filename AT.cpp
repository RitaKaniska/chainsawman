#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2e5 + 10;

int n,q;
int e[maxn];
int u[maxn][19];

void preprocess()
{
    cin >> n >> q;
    for(int i = 1; i < n; ++i)
    {
        cin >> e[i + 1];
        u[i + 1][0] = e[i + 1];
    }
    for(int j = 1; j < 18; ++j)
    {
        for(int i = 1; i <= n; ++i)
        {
            u[i][j] = u[u[i][j - 1]][j - 1];
        }
    }
}

int query(int x, int k)
{
    for(int j = 0; (1 << j) <= k; ++j)
    {
        if(k >> j & 1) x = u[x][j];
    }
    return x;
}

signed main()
{
    preprocess();
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        if(query(a,b)) cout << query(a,b);
        else cout << -1;
        cout << endl; 
    }
}