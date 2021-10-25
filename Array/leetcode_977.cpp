#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    for (int i = 0; i < (int)nums.size(); i++) {
        nums[i] = nums[i] * nums[i];
    }
    sort(nums.begin(), nums.end());
    return nums;
}
//双指针
vector<int> sortedSquares_2(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
        if (nums[i] * nums[i] > nums[j] * nums[j]) {
            ans[pos] = nums[i] * nums[i];
            ++i;
        }
        else {
            ans[pos] = nums[j] * nums[j];
            --j;
        }
        --pos;
    }
    return ans;
}

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> res = sortedSquares_2(nums);
    for(int e : res) {
        cout << e << " ";
    }
}