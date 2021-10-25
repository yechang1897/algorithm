#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n;
int f[N][N];//表示组成总和为i的j个数的所有方案

int main()
{
    cin >> n;

    f[1][1] = 1;
    for (int i = 2; i <= n; i ++ )
        for (int j = 1; j <= i; j ++ )
            f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % mod;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << f[i][j] << " ";
        cout << endl;
    }

    int res = 0;
    for (int i = 1; i <= n; i ++ ) res = (res + f[n][i]) % mod;

    cout << res << endl;

    return 0;
}