#include<iostream>
#include<algorithm>
using namespace std;

const int N = 3005;
int f[N][N];
int A[N];
int B[N];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> A[i]; 
    for(int i = 1; i <= n; i++) cin >> B[i];
    int res = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if(A[i] == B[j]) {
                f[i][j] = max(f[i][j], 1);
                for(int k = 1; k < j; k++) 
                    if(B[k] < B[j]) f[i][j] = max(f[i][j], f[i - 1][k] + 1);
            }
            res = max(res, f[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) res = max(res, f[n][i]);
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    cout << res << endl;
}

// #include <iostream>

// using namespace std;

// const int N = 3010;

// int n;
// int a[N], b[N];
// int f[N][N];

// // 此代码超时，需要优化，会出现 TLE
// int main() {

//     scanf("%d", &n);
//     for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
//     for (int i = 1; i <= n; i++) scanf("%d", &b[i]);

//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= n; j++) {
//             f[i][j] = f[i - 1][j];
//             if (a[i] == b[j]) {
//                 f[i][j] = max(f[i][j], 1);
//                 for (int k = 1; k < j; k++)  // 找到1~k-1中满足 b[k] < a[i] 的最大的f[i-1][k]
//                     if (b[k] < b[j])  // 因为a[i] == b[j]，所以改写为 if (b[k] < a[i])
//                         f[i][j] = max(f[i][j], f[i - 1][k] + 1);
//             }
//         }

//     int res = 0;
//     for(int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             cout << f[i][j] << " ";
//         }
//         cout << endl;
//     }
//     for (int i = 1; i <= n; i++) res = max(res, f[n][i]);

//     printf("%d\n", res);

//     return 0;
// }
