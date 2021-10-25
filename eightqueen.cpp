#include<iostream>
#include<algorithm>

using namespace std;
int row[11], n = 8;
int a[10][10] = {0};
int t = 1;
bool judge(int num) {
    for (int i = 1; i < num; i++) {
        if (row[num] == row[i] || abs(row[i] - row[num]) == num - i){
            return false;
        }
    }
    return true;
}  

void dfs(int num) {
    if (num >= 9) {
        cout << "no." << t++ << endl;
        for_each(row + 1, row + 9, [](int i){ cout << i << " "; }), cout << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    for (int i = 1; i <= n; i++) {
        row[num] = i;
        if (a[num][i] != 1 && judge(num)) {
            a[num][i] = 1;
            dfs(num + 1);
            a[num][i] = 0;
        }
    }
}

int main() {
    dfs(1);
    return 0;
}