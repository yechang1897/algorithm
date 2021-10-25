#include<iostream>
#include<vector>

using namespace std;

int missingNumber(vector<int>& nums) {
    int i = 0, j = (int)nums.size() - 1;
    while(i <= j) {
        int m = (i + j) / 2;
        if(nums[m] == m) i = m + 1;
        else j = m - 1;
    }
    return i;
}

int main() {
    vector<int> nums = {0,1};
    cout << missingNumber(nums);
}