#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int i = 0;
        for (int j = 1; j <(int) nums.size(); j++) {
            if(nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
}

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int j = removeDuplicates(nums);
    for (int i = 0; i < j; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}