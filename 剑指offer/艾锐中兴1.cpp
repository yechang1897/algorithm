#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minNum(vector<int>& nums, int pos) {
    vector<int> nums2 = nums;
    sort(nums2.begin(), nums2.end());
    int l = 0;
    int r = nums.size() - 1;
    while(l < r) {
        int mid = l + r + 1 >> 1;
        if(nums2[mid] <= pos) l = mid;
        else r = mid - 1;
    }
    //cout << l << endl;
    r = l + 1;
    int res = 0;
    int flag = 0;
    while(flag < nums.size()) {
        if(abs(pos - nums[l]) > abs(nums[r] - pos)) {
            res += abs(nums[r] - pos);
            pos = nums[r];
            if(r < nums.size() - 1) {
                r++;

            } else {
                nums[r] = INT_MAX;
            }
               
            flag++;
        } else {
            res += abs(pos - nums[l]);
            pos = nums[l];
            if(l > 0)
                l--;
            else  nums[l] = INT_MAX;
            flag++;
        }
        //cout << l << res << r <<endl;
    }
    // cout << res << endl;
    return res;
}

int main() {
    vector<int> nums = {2,1,5};
    int pos = 0;
    cout << minNum(nums, pos);
    return 0;
}