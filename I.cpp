#include<bits/stdc++.h>
#define int long long

using namespace std;

int a,b;
int dp[20][10][2][2];

int solve(string s,int curr,int prev,int zeros,int tight)
{
    if(curr == 0) return 1;
    if(dp[curr][prev][zeros][tight] != -1)
    {
        return dp[curr][prev][zeros][tight];
    }

    int limit;
    if(tight == 0) limit = 9;
    else
    {
        limit = s[s.size() - curr] - '0';
        //cout << limit <<endl;
    }
    int ans = 0;
    for(int digit = 0; digit <= limit; ++digit)
    {
        if((digit == prev) && zeros == 0) continue;

        int new_zeros = (digit == 0 && zeros == 1);
        int new_tight = ((digit == limit) && tight == 1);

        ans += solve(s,curr-1,digit,new_zeros,new_tight);
    }
    dp[curr][prev][zeros][tight] = ans;
    return dp[curr][prev][zeros][tight];
}

signed main()   
{
    cin >> a >> b;
    memset(dp, - 1, sizeof(dp));
    string sb = to_string(b);
    int ans1 = solve(sb,sb.size(),-1,1,1);
    memset(dp, -1, sizeof(dp));
     string sa = to_string(a - 1);
    int ans2 = solve(sa,sa.size(),-1,1,1);
    cout << ans1 - ans2 <<endl;
}