#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e6 + 10;
const long long inf = numeric_limits<long long>:: max()/2;
const int mod = 1e9 + 7;

int n;

struct matrix{
    int mat[2][2];
    matrix(){
        memset(mat,0,sizeof mat);
    }
    void I()
    {
        memset(mat,0,sizeof mat);
        for(int i = 0;i<2;++i) mat[i][i] = 1;
    }

    void fibo()
    {
        memset(mat, 0, sizeof mat);
        mat[0][0] = mat[0][1] = mat[1][0] = 1;
        mat[1][1] = 0;
    }
};

matrix mulmat(matrix a,matrix b)
{
    matrix ans;
    for(int i = 0;i < 2; ++i)
    {
        for(int j = 0; j < 2; ++i)
        {
            for(int  k = 0;k < 2; ++k)
            {
                ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j]);
                ans.mat[i][j] % mod;
            }
        }
    }
    return ans;
}

matrix expmat(matrix a,int m)
{
    matrix ans;
    if(m == 0)
    {
        ans.I();
        return ans;
    }
    if(m == 1)
    {
        return a;
    }
    if(m % 2 == 0)
    {
        matrix t = expmat(a,m/2);
        return mulmat(t,t);
    }
    if(m % 2 == 1)
    {
        matrix t = expmat(a,m/2);
        return mulmat(mulmat(t,t),a);
    }
}

signed main()
{
    cin >> n;
    matrix fibo;
    fibo.fibo();
    if(n == 0) cout << 0 <<endl;
    else
    {
        matrix ans = expmat(fibo,n-1);
        cout << ans.mat[0][0];
    }
}