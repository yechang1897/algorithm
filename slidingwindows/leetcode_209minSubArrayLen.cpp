#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
    deque<int> que;
    int sum = 0;
    int res = (int)nums.size() + 1;
    for (size_t i = 0; i < nums.size(); i++) {
        sum += nums[i];
        que.push_back(nums[i]);
        while(sum >= s) {
            res = min((int)que.size(), res);   
            sum -= que[0];
            que.pop_front();           
        }
    }
    return res == (int)nums.size() ? 0 : res;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int s = 15;
    cout << minSubArrayLen(s, nums);
}