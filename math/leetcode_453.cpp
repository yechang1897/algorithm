#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int minMoves(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int count = 0;
    for (int i = (int)nums.size() - 1; i >= 0; i--) {
        count += nums[i] - nums[0];
    }
    return count;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    cout << minMoves(nums);
}