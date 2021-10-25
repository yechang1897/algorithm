#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int len = (int)nums.size();
    int res = len;
    if(len == 1) {
            return target <= nums[0] ? 0 : len;
    }
    if(len == 2) {
        for(int i = 0; i < len; i++) {
            if(target <= nums[i]) {
                res = i;
                break;
            }
        }
        return res;
        cout << "hello";
    }
    int left = 0;
    int right = len - 1;
    int mid = (left + right) / 2;
    while(left < right) {
        // cout << "mid:" << mid << "left:" << left << "right:" << right << endl;
        if(target < nums[mid]) {
            right = mid;
            mid = (left + right) / 2;
        } else if(target > nums[mid]){
            left = mid;
            mid = (left + right) / 2; 
        } else {
            return mid;
            break;
        }
        if(left == right) {
            if(target < nums[left]) {
                return mid;
            } else {
                return mid + 1;
            }
        }
        cout << "mid:" << mid << "left:" << left << "right:" << right << endl;
        if(left == right - 1) {
            cout << "mid:" << mid << "left:" << left << "right:" << right<< endl;
            mid = left;
            if(left == 0) {
                if(nums[mid] >= target) {
                    return 0;
                    break;
                }
            } else if(right == len - 1){
                if(nums[right] < target) {
                    cout << len <<endl;
                    return len;
                    break;
                }
            }
            break;
        }
    }
    cout << "hello" <<endl;
    return mid + 1;
}

int searchInsert_2(vector<int>& nums, int target) {
    int b=0,e=nums.size()-1,mid;
        int r=-1;
        while(b<=e){
            mid=(b+e)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                b=mid+1;
                r=mid;
            }
            else{
                e=mid-1;
            }    
        }
    return r+1;
}

int main() {
    vector<int> nums = {1, 3, 5};
    int target = 1;
    cout << searchInsert_2(nums, target);
}