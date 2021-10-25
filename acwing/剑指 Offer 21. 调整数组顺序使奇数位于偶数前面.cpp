#include<iostream>
#include<vector>

using namespace std;

vector<int> exchange(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while(left < right) {
        if(nums[left] % 2 == 1) {
            left++;
            continue;

        }

        if(nums[right] % 2 != 1) {
            right--;
            continue;

        }
        swap(nums[left++], nums[right--]);
    }

    return nums;
}

int main() {
    vector<int> nums = {1, 2, 3 ,4};
    for(auto x : exchange(nums)) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}