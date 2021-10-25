#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int sizeN = (int)nums.size();
    int i = 0;
    for (int j = 0; j < sizeN; j++) {
        if(nums[j] != 0) {
            nums[i++] = nums[j];            
        }
    }

    for (int k = i; k < (int)nums.size(); k++) {
        nums[k] = 0;
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    for(int i : nums) {
        cout << i << " ";
    }
    return 0;
}