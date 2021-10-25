#include<iostream>
#include<vector>

using namespace std;

int rob(vector<int>& nums) {
    int sz = nums.size();
    vector<int> f(sz + 1);
    f[0] = 0;
    f[1] = nums[0];
    //偷第一家
    for (int i = 2; i < sz; i++) {
        f[i] = max(f[i - 2] + nums[i - 1], f[i - 1]);
    }
    vector<int> f2(sz + 1);
    f2[1] = 0;
    f2[2] = nums[1];
    //不偷第一家
    for (int i = 3; i <= sz; i++) {
        f2[i] = max(f2[i - 2] + nums[i - 1], f2[i - 1]);
    }
    return max(f[sz - 1], f2[sz]);
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << rob(nums);
    return 0;
}
