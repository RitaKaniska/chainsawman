#include<bits/stdc++.h>
#define int long long

using namespace std;

bool ask(string s)
{
    cout << "? " << s << endl;
    int response;
    cin >> response;
    return response;
}

void out(string s)
{
    cout << "! " << s << endl;
}

void solve()
{
    int n; 
    cin >> n;
    string s;
    while(s.size() < n)
    {
        if(ask(s + "0") == true)
        {
            s += "0";
        }
        else if(ask(s + "1") == true)
        {
            s += "1";
        }
        else
        {
            break;
        }
    }
    while((int)s.size() < n)
    {
        if(ask("0" + s) == true) s = "0" + s;
        else s = "1" + s;
    }
    out(s);
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