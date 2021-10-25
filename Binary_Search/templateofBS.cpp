#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int binary_Search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    int mid = 0;
    while(l < r) {
        mid = l + r >> 1;
        if(nums[mid] >= target) r = mid;
        else l = mid + 1;
    }
    cout << l << " " << r  << " " << mid << endl;
    return l;
}

int binary_Search_2(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    int mid = 0;
    while(l < r) {
        mid = l + r + 1 >> 1;
        if(nums[mid] <= target) l = mid;
        else r = mid - 1;
    }
    cout << l << " " << r  << " " << mid << endl;
    return l;
}

int main() {
    vector<int> nums = {1, 3, 9, 20 , 21};
    cout << binary_Search(nums, 9) << endl;
    cout << binary_Search_2(nums, 9) << endl;
    cout << binary_Search(nums, 8) << endl;
    cout << "----------------" << endl;
    vector<int> nums2 = {1, 1, 1, 1 , 1};
    cout << binary_Search(nums2, 1) << endl;
    cout << binary_Search_2(nums2, 1) << endl;
    cout << binary_Search(nums2, 9) << endl;
}