#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s = "";
    int cnt = n / 5 ;
    for(int i = 0 ; i < cnt && s.size() < n ;++i) s += 'a';
    if(n % 5 >= 1 && n % 5 != 0) s += 'a';
    for(int i = 0 ; i < cnt && s.size() < n ;++i) s += 'e';
    if(n % 5 >= 2 && n % 5 != 0) s += 'e';
    for(int i = 0 ; i < cnt && s.size() < n ;++i) s += 'i';
    if(n % 5 >= 3 && n % 5 != 0) s += 'i';
    for(int i = 0 ; i < cnt && s.size() < n ;++i) s += 'u';
    if(n % 5 >= 4 && n % 5 != 0) s += 'u';
    for(int i = 0 ; i < cnt && s.size() < n ;++i) s += 'o';
    cout << s << endl;
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