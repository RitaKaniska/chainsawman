/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long INF = numeric_limits<long long>::max() / 2;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

int g[N];

void precal(){
    g[0] = 0; g[1] = 0;
    for(int i = 2; i < N; ++i){
        vector <int> v;
        for(int x = 1; x * x <= i; ++x){
            int y = i / x;

            if (i % x == 0){
                if (x & 1){
                    v.push_back(g[y]);
                }
                if (y & 1){
                    v.push_back(g[x]);
                }
            }
        }
        sort(v.begin(), v.end());
        v.push_back(MAXA);
        for(int j = 0; j + 1 < (int)v.size(); ++j){
            if (v[j + 1] - v[j] >= 2){
                g[i] = v[j] + 1;
                break;
            }
        }

        cout << i <<" : " <<g[i] <<endl;
    }
}

void solve()
{
    int n; cin >> n;
    int sumxor = 0;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        sumxor ^= g[x];
    }
    if (sumxor == 0) cout << 2 << endl;
    //else cout << 1 << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);

    precal();
    int t = 1; cin >> t;
    while (t--)
    {
        solve();
    }
}