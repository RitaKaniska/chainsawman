#include<bits/stdc++.h>
//#define int long long
typedef long long ll;

using namespace std;

ll euclid(ll a,ll b,ll &x,ll &y){
 if (!b) return x=1,y=0,a;
 ll d=euclid(b,a%b,y,x);
 return y-=a/b * x,d;
 }

 ll crt(ll a,ll m,ll b,ll n){
 if (n>m)swap(a,b),swap(m,n);
 ll x,y,g=euclid(m,n,x,y);
 assert((a-b)%g==0);// else no solution
 x=(b-a)%n * x%n/g * m+a;
 return x<0?x+m*n/g:x;
 }

void solve()
{
    int a, m ,b , n;
    cin >> a >> m >> b >> n;
    cout << crt(a,m,b,n) <<' '<< m * n << endl;
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