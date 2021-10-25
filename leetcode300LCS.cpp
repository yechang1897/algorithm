#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int maxLIS(vector<int> &nums) {
    vector<int> dp(nums.size(),1);
    for (int i = 1; i < (int)nums.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            dp[i] = nums[i] > nums[j] ? max(dp[i],dp[j] + 1) : dp[i];
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> nums = {2, 1, 5, 6, 2 ,3};
    cout << maxLIS(nums) << endl;
    return 0;
}