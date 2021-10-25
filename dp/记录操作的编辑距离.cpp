#include<iostream>
#include<string>

using namespace std;

struct Node{
    int val;
    int choice;
    /*
    0代表什么都不做
    1代表插入
    2代表删除
    3代表替换  
    */
};

const int N = 5e2 + 5;

Node* f[N][N];

int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    if(n * m == 0) {
        return n + m;
    }
    for(int i = 0; i <= n; i++){   
        f[i][0]->val = i;
        f[i][0]->choice = 1;  
    }

    for(int i = 0; i <= m; i++){
        f[0][i]->val = i;
        f[0][i]->choice = 1;
    }
    cout << f[0][1]->val << endl;

    for(int i = 1 ; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(word1[i - 1] == word2[j - 1]) {
                f[i][j]->val = f[i - 1][j - 1]->val;
                f[i][j]->choice = 0;
            } else {
                int minVal = min(min(f[i - 1][j]->val, f[i][j - 1]->val), f[i - 1][j - 1]->val);
                f[i][j]->val = minVal;
                if(minVal == f[i - 1][j]->val) f[i][j]->choice = 1;
                if(minVal == f[i][j - 1]->val) f[i][j]->choice = 2;
                if(minVal == f[i - 1][j - 1]->val) f[i][j]->choice = 3;
            }
        }
    }
    for(int i = 0 ; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << f[i][j]->choice << " ";
        }
        cout << endl;
    }
    return f[n][m]->val;
}

int main() {
    string word1 = "horse", word2 = "ros";
    cout << minDistance(word1, word2);
    return 0;
}