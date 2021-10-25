#include<iostream>
#include<string>

using namespace std;
const int N = 1005;
int f[N][N];

int main() {
    string A,B;
    cin >> A >> B;
    int sa = A.size();
    int sb = B.size();
    for(int i = 1; i <= sa; i++) f[i][0] = i;
    for(int i = 1; i <= sb; i++) f[0][i] = i;

    for(int i = 1; i <= sa; i++) {
        for(int j = 1; j <= sb; j++) {
            if(A[i - 1] == B[j - 1])
                f[i][j] = f[i - 1][j - 1];
            else f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
        }
    }
    for(int i = 0; i <= sa; i++) {
        for(int j = 0; j <= sb; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    cout << f[sa][sb] << endl;
    return 0;
}