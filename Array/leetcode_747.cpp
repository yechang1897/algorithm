#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int dominantIndex(vector<int>& nums) {
    int sz = (int)nums.size();
    int maxN = 0;
    int res = 0;
    for (int i = 0; i < sz; ++i) {
        maxN = max(maxN, nums[i]);
    }
    int flag = 1;
    for (int i = 0; i < sz; ++i) {
        if(nums[i] == maxN && flag == 1) {
            flag--;
            res = i;
        } else if (nums[i] * 2 > maxN) {
            return -1; 
        }
    }
    return res;
}

int main() {
    vector<int> nums = {3, 6, 1, };
    cout << dominantIndex(nums);
}