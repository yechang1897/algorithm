#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> nums, int target) {
    int l = 0, r = nums.size();
    // cout << l << " " << r << endl;
    while(l < r) {        
        int mid = l + r + 1 >> 1;
        // cout << mid << endl;
        if(nums[mid] <= target) l = mid;
        else r =  mid - 1;
    }
    cout << l << endl;
    return nums[l] == target ? l : -1;
}

/*
    while(l < r) {
        int mid = l + r >> 1;
        if(a[mid] > t) r = mid;
        else l = mid + 1;
    }
    return l;
*/

/*
while(l < r) {
        int mid = l + r + 1 >> 1;
        if(a[mid] < t) l = mid;
        else r = mid - 1;
    }
    return l;
*/

int main() {
    vector<int> nums = {2, 4, 5, 7, 8, 9};
    int target = 4;
    cout << binarySearch(nums, target);
    return 0; 
}