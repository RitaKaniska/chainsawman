#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2e5 + 10;
const int inf = 1e9 + 7;
const int BL = 500;

int n,q,a[maxn];
int idblock[maxn];
int L[BL],R[BL],sumblock[BL];
int cntblock = 0;

void solve()
{
    cin >> n >> q;
    for(int i = 1;i <= BL; ++i)
    {
         L[i] = R[i] = 0;
    }
    for(int i = 1;i <= n; ++i)
    {
        cin >> a[i];
        //cout << a[i] <<endl;
        if(i % BL == 1) ++cntblock;
        //cout << cntblock << endl;
        if(L[cntblock] == 0)
        {
            L[cntblock] = R[cntblock] = i;
        }
        else R[cntblock] = i;
        idblock[i] = cntblock;
        sumblock[cntblock] += a[i];
        //cout << sumblock[cntblock] <<endl;
    }

    int query,b,c;
    while(q--)
    {
        cin >> query >> b >> c;
        if(query == 1)
        {
            sumblock[idblock[b]] += (c - a[b]);
            //cout << sumblock[idblock[b]] << endl;
            a[b] = c;
        }
        if(query == 2)
        {
            int ans = 0;
            for(int i = 1;i <= cntblock;++i)
            {
                if(R[i] < b || L[i] > c) continue;
                else if(L[i] >= b && R[i] <= c)
                {
                    ans += sumblock[i];
                    continue;
                }
                for(int j = L[i]; j <= R[i]; ++j)
                {
                    if(j >= b && j <= c) ans += a[j];
                }
            }
            cout << ans << endl;
        }
    }
}

signed main()
{
    solve();
}