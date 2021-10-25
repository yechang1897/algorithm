#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int binary_Search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while(l < r) {
        int mid = l + r >> 1;
        if(nums[mid] >= target) r = mid;
        else l = mid + 1;
    }
    return l;
}

int binary_Search_2(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while(l < r) {
        int mid = l + r + 1 >> 1;
        if(nums[mid] <= target) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {
    vector<int> nums = {1, 3, 3, 9, 20, 21,};
    cout << binary_Search(nums, 3) << endl;
    cout << binary_Search_2(nums, 3) << endl;
    cout << binary_Search(nums, 4) << endl;
    cout << binary_Search_2(nums, 4) << endl;
    cout << "----------------" << endl;
    vector<int> nums2 = {1, 1, 1, 1 ,1,3};
    cout << binary_Search(nums2, 1) << endl;
    cout << binary_Search_2(nums2, 1) << endl;
    cout << binary_Search(nums2, 2) << endl;
    cout << binary_Search_2(nums2, 2) << endl;
    return 0;
}