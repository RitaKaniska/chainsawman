#include<bits/stdc++.h>
#define int long long

using namespace std;

string s;
vector<int> pi;
vector<int> z;

vector<int> kmp(string s)
{
    int sz = s.size();
    vector<int> pi(sz,0);
    for(int i = 1; i < sz; ++i)
    {
        int k = pi[i-1];
        while(k > 0 && s[k] != s[i]) k = pi[k-1];
        pi[i] = k + (s[i] == s[k]);
    }
    return pi;
}

vector<int> z_func(string s)
{
    int sz = s.size();
    vector<int> z(sz);
    for(int i = 1, l = 0, r = 0; i < sz; ++i)
    {
        if(i <= r)
        {
            z[i] = min(r - i + 1,z[i-l]);
        }
        while(i + z[i] < sz && s[z[i]] == s[z[i] + i]) ++z[i];  
        if(i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

signed main()
{
    cin >> s;
    pi = kmp(s);
    z = z_func(s);
    for(int i = 0; i < z.size();++i)
    {
        cout << z[i] <<" ";
    }
    cout << endl;
    for(int i = 0; i < pi.size();++i)
    {
        cout << pi[i] << " ";
    }
}