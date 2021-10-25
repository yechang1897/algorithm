#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int maximumWealth(vector<vector<int>>& accounts) {
    int sz = accounts.size();
    int res = 0;
    int temp = 0;
    for (int i = 0; i < sz; i++) {
        for(int i : accounts[i]) {
            temp += i;
        }
        res = max(res, temp);
        temp = 0;
    }
    return res;
}

int main() {
    vector<vector<int>> accounts = {{1,2,3},{3,2,1}};
    cout << maximumWealth(accounts);
}