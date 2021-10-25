#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

int missingNumber(vector<int>& nums) {
    int sz = (int)nums.size();
    vector<int> times(sz + 1, 0);
    int res = 0;
    for (int i = 0 ; i < sz; ++i) {
        times[nums[i]] = 1;
    }
    for (int i = 0; i < sz + 1; ++i) {
        if (times[i] == 0) {
            res = i;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    cout << missingNumber(nums);
}