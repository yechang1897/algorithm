#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0) {
        return 0;
    }
    int i = 0;
    int flag = 1;
    for (int j = 1; j < (int)nums.size(); j++) {
        if (nums[j] != nums[i]) {
            flag = 1;
            i++;
            nums[i] = nums[j];
        } else {
            flag++;
            if (flag <= 2) {
                i++;
                nums[i] = nums[j];
            }
        }
    }
    return i + 1;
}

int removeDuplicates_2(vector<int>& nums) {
       if(nums.empty()) return 0;
        int j = 0;
        bool flag = true;
        for(int i = 1; i < (int)nums.size(); i++) {
            if(nums[i] == nums[j] && flag) {
                flag = false;
                nums[++j] = nums[i];
            }
            else if(nums[i] != nums[j]) {
                if(!flag) flag = true;
                nums[++j] = nums[i];
            }
            else {}
        }
        return j + 1;
}

int main() {
    vector<int> nums = {0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int j = removeDuplicates_2(nums);
    for (int i = 0; i < j; i++) {
        cout << nums[i] << " ";
    }
    return 0; 
}