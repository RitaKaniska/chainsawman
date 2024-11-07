#include<bits/stdc++.h>
#define int long long

using namespace std;

const int K = 2;
const int mod = 1e9 + 7;

struct matrix
{
    int mat[K][K];

    matrix()
    {
        memset(mat,0,sizeof mat);
    }

    void I()
    {
        memset(mat, 0 , sizeof mat);
        for(int i = 0; i < K;++i)
        {
            mat[i][i] = 1;
        }
    }
    void Fibo()
    {
        //memset(mat , 0 , sizeof mat);
        mat[0][0] = 1;
        mat[0][1] = 1;
        mat[1][0] = 1;
        mat[1][1] = 0;
    }
};

matrix mulmat(matrix A,matrix B)
{
    matrix ans;
    for(int i = 0; i < K ; ++i)
    {
        for(int j = 0; j < K; ++j)
        {
            for(int k = 0; k < K; ++k)
            {
                ans.mat[i][j] += (A.mat[i][k] * B.mat[k][j]);
                ans.mat[i][j] %= mod;
            }
        }
    }
    return ans;
}

matrix binmulmat(matrix A,int m)
{
    matrix ans;
    if(m == 0)
    {
        ans.I();
        return ans;
    }
    if(m == 1)
    {
        return A;
    }
    if(m % 2 == 0)
    {
        matrix t = binmulmat(A, m / 2);
        return mulmat(t,t);
    }
    if(m % 2 == 1)
    {
        matrix t = binmulmat(A, m / 2);
        return mulmat(mulmat(t,t),A);
    }
}

signed main()
{
    int n;
    cin >> n;
    matrix fibo;
    fibo.Fibo();

    if(n == 0)
    {
        cout << 0;
    }
    else
    {
        matrix ans = binmulmat(fibo, n - 1);
        cout << ans.mat[0][0] << endl;
    }
}