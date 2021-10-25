#include<iostream>
#include<string>

using namespace std;

const int N = 5e2 + 5;

int f[N][N];

int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    if(n * m == 0) {
        return n + m;
    }
    for(int i = 0; i <= n; i++){
        f[i][0] = i;      
    }

    for(int i = 0; i <= m; i++){
        f[0][i] = i;
    }

    for(int i = 1 ; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]);
            if(word1[i - 1] == word2[j - 1]) f[i][j] = min(f[i][j] + 1, f[i - 1][j -1]);
            else f[i][j] = min(f[i][j], f[i - 1][j -1]) + 1;
        }
    }
    for(int i = 0 ; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    return f[n][m];
}

int main() {
    string word1 = "horse", word2 = "ros";
    cout << minDistance(word1, word2);
    return 0;
}