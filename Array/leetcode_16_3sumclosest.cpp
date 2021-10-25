#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
//暴力破解O(n^3)
//如何转换为O(n^2)
//固定一个数，转换为twosum问题。
int threeSumClosest(vector<int>& nums, int target) {
    int res = nums[0] + nums[1] + nums[2];
    int dif = abs(target - res);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < (int) nums.size(); i++) {
        int left = i + 1, right = (int)nums.size() - 1;
        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            int newDif = abs(target - sum);
            if (dif > newDif) {
                res = sum;
                dif = abs(target - sum);
            }
            if(sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    return res;
} 

int main() {
    vector<int> nums = {-1,2,1,-4};
    // vector<int> nums = {-4, -1, 1, 2};
    int target = 1;
    cout << threeSumClosest(nums, target);
}