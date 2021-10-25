#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int sz =  (int) nums.size();
    int dup = -1;
    int missing = 1;
    vector<int> res;
    for (int i = 1; i < sz; ++i) {
        if (nums[i] == nums[i - 1])
                dup = nums[i];
        else if (nums[i] > nums[i - 1] + 1)
                missing = nums[i - 1] + 1;
    }
    res.emplace_back(dup);
    nums[sz - 1] != sz ? res.emplace_back(sz) : res.emplace_back(missing);
    return res;
}

int main() {
    // vector<int> nums = {1,2,2,4};
    vector<int> nums = {2,2};
    // vector<int> nums = {1,1};
    // vector<int> nums = {1,5,3,2,2,7,6,4,8,9};
    // vector<int> nums = {3,2,3,4,6,5};
    cout << findErrorNums(nums)[0]  << " "<< findErrorNums(nums)[1];
}