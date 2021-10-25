#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> res;
vector<int> t;



void dfs(bool choosen ,vector<int>& nums, int k) {
    if(k == nums.size()) {
        res.push_back(t);
        return;
    }

    dfs(nums, k + 1);

    if(i > 0 && nums[i - 1] != nums[i]) continue;
    t.push_back(nums[k]);
    dfs(nums, k + 1);
    t.pop_back();
}

int main() {
    vector<int> nums = {1,1,3};
    sort(nums.begin(), nums.end());
    dfs(false, nums, 0);
    for(auto x : res) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}