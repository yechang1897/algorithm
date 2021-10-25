#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1) return;
    int i = len - 2;
    bool isSorted = true;
    while(i >= 0) {
        if (nums[i] < nums[i+1]) {
            isSorted = false;
            break;
        }
        i--;
    }
    if (isSorted) {
        sort(nums.begin(), nums.end());
    }
    int j = len - 1;
    while (i < j) {
        if (nums[i] < nums[j]){
            swap(nums[i], nums[j]);
            break;
        }
        j--;
    }
    reverse(nums.begin() + i + 1, nums.end());
}



int main(){
    vector<int> nums = {1,1};
    nextPermutation(nums);
    for (int i = 0; i < (int)nums.size(); i++) {
        cout << nums[i] << " ";
    }
}