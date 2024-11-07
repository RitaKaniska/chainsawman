#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    string s;
    string ans;
    cin >> s;
    s += '0';
    char curchar = s[0];
    int cnt = 1;
    for(int i = 1; i < s.size(); ++i)
    {
        if(curchar == s[i]) cnt++;
        else
        {
            if(curchar == '2')
            {
                if(cnt % 3 == 1) ans += 'a';
                if(cnt % 3 == 2) ans += 'b';
                while(cnt / 3 > 0)
                {
                    ans += 'c';
                    cnt -= 3;
                }
            }
            if(curchar == '3')
            {
                if(cnt % 3 == 1) ans += 'd';
                if(cnt % 3 == 2) ans += 'e';
                while(cnt / 3 > 0)
                {
                    ans += 'f';
                    cnt -= 3;
                }
            }
            if(curchar == '4')
            {
                if(cnt % 3 == 1) ans += 'g';
                if(cnt % 3 == 2) ans += 'h';
                while(cnt / 3 > 0)
                {
                    ans += 'i';
                    cnt -= 3;
                }
            }
            if(curchar == '5')
            {
                if(cnt % 3 == 1) ans += 'j';
                if(cnt % 3 == 2) ans += 'k';
                while(cnt / 3 > 0)
                {
                    ans += 'l';
                    cnt -= 3;
                }
            }
            if(curchar == '6')
            {
                if(cnt % 3 == 1) ans += 'm';
                if(cnt % 3 == 2) ans += 'n';
                while(cnt / 3 > 0)
                {
                    ans += 'o';
                    cnt -= 3;
                }
            }
            if(curchar == '7')
            {
                if(cnt % 4 == 1) ans += 'p';
                if(cnt % 4 == 2) ans += 'q';
                if(cnt % 4 == 3) ans += 'r';
                while(cnt / 4 > 0)
                {
                    ans += 's';
                    cnt -= 4;
                }
            }
            if(curchar == '8')
            {
                if(cnt % 3 == 1) ans += 't';
                if(cnt % 3 == 2) ans += 'u';
                while(cnt / 3 > 0)
                {
                    ans += 'v';
                    cnt -= 3;
                }
            }
            if(curchar == '9')
            {
                if(cnt % 4 == 1) ans += 'w';
                if(cnt % 4 == 2) ans += 'x';
                if(cnt % 4 == 3) ans += 'y';
                while(cnt / 4 > 0)
                {
                    ans += 'z';
                    cnt -= 4;
                }
            }
            curchar = s[i];
            cnt = 1;
        }
    }
    cout << ans << endl;
}

signed main()
{
    solve();
}