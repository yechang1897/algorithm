#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;

int nums[10];
vector<vector<int>> res;
vector<int> temp(10);
void dfs(int n) {
    if(n == 0) {
        res.push_back(temp);
        return;
    };
    for(int i = 0; i < 10; i++) {
        temp[i] = 1;
        dfs(n - 1);
        temp[i] = 0;
    }
}

string transfer(vector<int> t) {
    int hour = 0;
    for(int i = 3; i >= 0; i--) {
        hour += pow(2, 3 - i) * t[i];
    }
    int min = 0;
    for(int i = 9; i >= 4; i--) {
        min += pow(2, 9 - i) * t[i];
    }
    return to_string(hour) + ":" + to_string(min);
}

int main() {
    dfs(1);
    int x = res.size();
    vector<string> ans;
    // for(int i = 0; i < x;i++) {
    //     for(int j = 0; j < 10; j++) {
    //         cout << res[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for(int i = 0; i < x; i++) {
        ans.push_back(transfer(res[i]));
    }
    for(auto str:ans) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}