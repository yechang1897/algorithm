#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
// 长度为n的最大连续子数组和 暴力破解法
int maxSubSum(vector<int>& nums, int n) {
    int len = (int)nums.size();
    int res = 0;
    for (int i = 0; i < len - n; i++) {
        int tempSum = 0;
        for (int j = i; j < i + n; j++) {
            tempSum += nums[j];
        }
        res = max(res, tempSum);
        cout << tempSum << " " << res << endl;
    }
    return res;
}

int maxSubSum_2(vector<int>& nums, int n) {
    int len = (int)nums.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += nums[i];
    }
    if (n >= len) {
        return res;
    }
    int windomSum = res;
    for (int i = n; i < len; i++) {
        windomSum += nums[i] - nums[i - n];
        cout << windomSum << " ";
        res = max(res, windomSum);
    }
    cout << endl;
    return res;
}




int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubSum_2(nums, 3) << endl;
}