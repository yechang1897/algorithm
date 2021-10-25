#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> res;
vector<int> t;
bool vis[20];

bool check(vector<vector<int>> flowers) {
    int m = flowers.size();
    int n = flowers[0].size();

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0) {
                if(j == 0) {
                    if(flowers[i][j] == flowers[i + 1][j] || flowers[i][j] == flowers[i][j + 1]) {
                        return false;
                    }
                } else if(j == n - 1) {
                    if(flowers[i][j] == flowers[i - 1][j] || flowers[i][j] == flowers[i][j + 1]) {
                        return false;
                    }
                } else {
                    if(flowers[i][j] == flowers[i + 1][j] || flowers[i][j] == flowers[i][j + 1] || flowers[i][j] == flowers[i][j - 1]) {
                        return false;
                    }
                }
            } else if(i == m - 1) {
                if(j == 0) {
                   if(flowers[i][j] == flowers[i - 1][j] || flowers[i][j] == flowers[i][j + 1]) {
                        return false;
                    } 
                } else if(j == n - 1) {
                    if(flowers[i][j] == flowers[i - 1][j] || flowers[i][j] == flowers[i][j - 1]) {
                        return false;
                    }
                } else {
                    if(flowers[i][j] == flowers[i - 1][j] || flowers[i][j] == flowers[i][j + 1] || flowers[i][j] == flowers[i][j - 1]) {
                        return false;
                    }
                }
            } else {
                if(flowers[i][j] == flowers[i - 1][j] || flowers[i][j] == flowers[i][j + 1] || flowers[i][j] == flowers[i][j - 1] || flowers[i][j] == flowers[i + 1][j]) {
                        return false;
                }
            }           
        }
    }
    return true;
}

void dfs(vector<int>& color, int sz, int k) {
    if(k == sz) {
        res.push_back(t);
        return;
    }

    for(int i = 0; i < sz; i++) {
        if(vis[i]) continue;
        t.push_back(color[i]);
        vis[i] = true;
        dfs(color, sz, k + 1);
        vis[i] = false;
        t.pop_back();
    }
}


int main() {
    int n = 1, m = 5;
    vector<int> nums = {4, 1};
    int sz = nums.size();
    vector<int> color;
    for(int i = 0; i < sz; i++) {
        for(int j = 0; j < nums[i]; j++) {
            color.push_back(i);
        }
    }

    // for(auto x : color) cout << x << " ";
    // cout << endl;
    dfs(color, color.size(), 0);
    // for(auto x : res) {
    //     for(auto y : x) {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
    vector<vector<int>> flowers(n, vector<int>(m, 0));
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            int x = j / m;
            int y = j % m;
            flowers[x][y] = res[i][j];
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << flowers[i][j] << " ";
            }
            cout << endl;
        }

        if(check(flowers)) {
            cout << "h" << endl;
            cout << true << endl;
            return 0;
        }
    }

    cout << false << endl;
    return 0;
}