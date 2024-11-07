#include<bits/stdc++.h>
#define int long long

using namespace std;

string s;
vector<int> z,pi;

vector <int> z_func(string s) {
    int sth = s.size();
    vector<int> z (sth,0);
    z[0] = 0;

    int l = 0, r = 0;
    for(int i = 1; i < sth;++i)
    {
        if(i <= r)z[i] = min(z[i-l],r - i + 1);

        while(z[i] + i < sth && s[z[i]] == s[z[i] + i])
        {
            z[i]++;
        }

        int l2 = i;
        int r2 = i + z[i] - 1;

        if(r2 > r)
        {
            r = r2;
            l = l2;
        }
    }
    return z;
}

vector <int> kmp(string s) {
    int sth = s.size();
    vector<int> pi(sth,0);
    pi[0] = 0;
    for(int i=1;i< sth;++i)
    {
        int k = pi[i-1];
        while(k > 0 && s[k] != s[i]) k = pi[k - 1];
        pi[i] = k + (s[i] == s[k]);
    }

    return pi;
}

signed main()
{
    cin>>s;
    z = z_func(s);
    pi = kmp(s);
    for(int i = 0;i<s.size();++i)
    {
        cout<<z[i]<<' ';
    }
    cout<<endl;
    for(int i = 0;i < s.size();++i) cout<<pi[i]<<' ';
    cout<<endl;
}