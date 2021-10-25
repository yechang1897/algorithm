#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// vector<vector<int>> res;
vector<int> temp;
int vis[15];
int sum;
int res = INT_MAX;

vector<int> nums = {9090400, 8499400, 5926800, 8547000, 4958200, 4422600, 5751200, 4175600, 6309600, 5865200, 6604400, 4635000, 10663400, 8087200, 4554000};

void dfs(int l, int r) {
    if(l > r) {
        int t = 0;
        if(temp.empty()) return;
        for(auto x : temp) {
            t += x;
        }
        // cout << t << endl;
        res = min(res, abs((sum - t) - t));
        return;
    }

    dfs(l + 1, r);

    temp.push_back(nums[l]);
    dfs(l + 1, r);
    temp.pop_back();
}

int main() {    
    for(auto x : nums) {
        sum += x;
    }
    // cout << sum << endl;
    dfs(0, 15);
    cout << res << endl;
}

/*
4554000
*/