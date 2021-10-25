#include<iostream>
#include<vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int sz = nums.size();
    int f[sz];
    f[0] = nums[0];
    int res = 0;
    for(int i = 1; i < sz; i++) {
        if(f[i - 1] > 0) f[i] =  f[i - 1] + nums[i];
        else f[i] = max(f[i - 1], nums[i]);
    }
    for(int i = 0; i < sz; i++)  res = max(res, f[i]);
    cout << endl;
    return res;
}

int main() {
    vector<int> nums = {1, -1, -2};
    cout << maxSubArray(nums) << endl;
    return 0;
}