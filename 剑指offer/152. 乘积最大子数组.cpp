#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int maxProduct(vector<int>& nums) {
    int sz = nums.size();
    int f[sz];
    int f2[sz];
    memset(f, 0, sizeof f);
    memset(f, 0, sizeof f2);
    f[0] = nums[0];
    f2[0] = nums[0];
    int res = 0;
    for(int i = 1 ; i < nums.size(); i++) {
        f[i] = max(f2[i - 1] * nums[i], max(f[i - 1] * nums[i], nums[i]));
        f2[i] = min(f[i - 1] * nums[i], min(f2[i - 1] * nums[i], nums[i]));
        res = max(res, f[i]);
    }
    return res;
}

int main() {
    vector<int> nums = {2, -3, -2, 4};
    cout << maxProduct(nums);
}