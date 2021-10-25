#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int maxSumOfSubSet(vector<int> &nums){
    int dp[nums.size()];
    dp[0] = nums[0];
    int maxSum = -INT_MAX;
    for (int i = 1; i < (int)nums.size();i++){
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        if (maxSum < dp[i]) {
            maxSum = dp[i];
        }
    }
        return maxSum;
}

int main(){
    vector<int> nums = {1, 2, 4, -7, -3, 2, 3};
    cout << maxSumOfSubSet(nums);
    return 0;
}