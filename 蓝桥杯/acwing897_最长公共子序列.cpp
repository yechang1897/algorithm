#include<iostream>
#include<string>
using namespace std;

const int N = 1005;
int f[N][N];
int n, m;

int main() {
    cin >> n >> m;
    string A;
    string B;
    cin >> A;
    cin >> B;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(A[i - 1] != B[j - 1]) f[i][j] = max(f[i -1][j], f[i][j -1]);
            else f[i][j] = f[i - 1][j - 1] + 1;
        }
    }

    cout << f[n][m] << endl;
    return 0;
}