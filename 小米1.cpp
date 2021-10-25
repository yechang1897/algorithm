#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxN = 1000;
int f[maxN][maxN];

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    int sz1 = (int)str1.size();
    int sz2 = (int)str2.size();    
    memset(f, 0, sizeof f);
    // for (int i = 1; i <= sz1; i++) {
    //     if(str1[0] == str2[i - 1])
    //         f[1][i] = 1;
    // }
    // for (int i = 1; i <= sz2; i++) {
    //     if(str2[0] == str1[i - 1])
    //         f[i][1] = 1;
    // }

    for (int i = 1; i <= sz1; i++) {
        for (int j = 1; j <= sz2; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if(str1[i - 1] == str2[j - 1])
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + 1;
        }
    }
    // for (int i = 1; i <= sz1; i++) {
    //     for (int j = 1; j <= sz2; j++) {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << f[sz1][sz2];
}