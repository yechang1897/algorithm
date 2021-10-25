#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int rob(vector<int>& nums) {
    int s = (int)nums.size();
    if (s <= 2)
        return *max_element(nums.begin(), nums.end());
    nums[1] = max(nums[0], nums[1]);
    for (int i = 2; i < s; i++) {
        nums[i] = max(nums[i - 1], nums[i] + nums[i - 2]);
    }
    return nums[s - 1];
}

int main() {
    vector<int> nums = {2, 1, 1, 2};
    cout << rob(nums) << endl;
}
