#include<bits/stdc++.h>
#define int __int128

//typedef __int128 in_128;

using namespace std;

const int k = 2;

struct matrix
{
    int mat[k][k];
    matrix()
    {
        memset(mat, 0 ,sizeof(mat));
    }

    void I()
    {
        for(int i = 0; i < k; ++i)
        {
            mat[k][k] = 1;
        }
    }
    void Fibo()
    {
        mat[0][0] = mat[0][1] = mat[1][0] = 1;
        mat[1][1] = 0;
    }
};

    matrix mulmat(matrix a, matrix b)
    {
        matrix ans;
        for(int i = 0; i < k ;++i)
        {
            for(int j = 0; j < k; ++j)
            {
                for(int t = 0; t < k ; ++t)
                {
                    ans.mat[i][j] += a.mat[i][t] * b.mat[t][j];
                }
            }
        }
        return ans;
    }

    matrix binmulmat(matrix a,int m)
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
            matrix t = binmulmat(a,m/2);
            return mulmat(t,t);
        }
        if(m % 2 == 1)
        {
            matrix t = binmulmat(a,m/2);
            return mulmat(mulmat(t,t),a);
        }
    }

int a,b,m;

void solve()
{
    matrix fibo;
    fibo.Fibo();
    cin >> a >> b >> m;
    matrix a1 = binmulmat(fibo,a - 1);
    matrix b1 = binmulmat(fibo,b - 1);
    int a2 = a1.mat[0][0];
    int b2 = b1.mat[0][0];
    //cout << a2 << ' ' << b2 << endl;
    int ans = (__gcd(a2,b2)) % m;
    cout << ans << endl;
}

signed main()
{
    solve();
}