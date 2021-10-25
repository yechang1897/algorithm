#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

int steps = 0;

bool isDone(vector<int> nums) {
    for(int i = 0 ; i < (int)nums.size(); ++i) {
        if(nums[i] == 0) {
            return false;
        }
    }
    return true;
}

void change(vector<int>& nums, int i) {
    int sz = nums.size();
    if(i == 0) {
        nums[sz - 1] = (nums[sz - 1] + 1) % 2;
        nums[i + 1] = (nums[i + 1] + 1) % 2;
    }
    if(i == sz - 1) {
        nums[i - 1] = (nums[i - 1] + 1) % 2;
        nums[0] = (nums[0] + 1) % 2;
    }
    nums[i - 1] = (nums[i - 1] + 1) % 2;
    nums[i + 1] = (nums[i + 1] + 1) % 2;

}
int res = 0;
int minNum(vector<int>& nums, int i) {
    if(isDone(nums)) {
        return res;
    }
    for(int i = 0; i < (int)nums.size(); i++) {
        change(nums, i);
        steps++;
        change(nums, i);
        steps--;
    }
    res = max(res, steps);
    return res;
}

int main() {
    vector<int> nums = {0, 1, 1 , 0, 0,0,1,0,0,1};
    cout << minNum(nums, 0);
}