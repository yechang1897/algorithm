#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> nums = {1,2,3,4};
    int sz = nums.size();
    int target = 1;
    if(nums.size() == 1)
        return 0;
    int l = 0, r = nums.size() - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) cout << mid << endl;
        if (nums[0] <= nums[mid]) {
            if (nums[0] <= target && target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[sz - 1]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    // cout << nums[r] << endl;
    //cout << l << " " << nums[l] << endl;
    return 0;
}