#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int longestSubarray(vector<int>& nums, int limit) {
    int sz = (int)nums.size();
    // cout << sz << endl;
    vector<int> dp(sz, 1);
    int breakEle = -1;
    int breakPos = 0;
    for(int i = 1; i < sz;i++) {
        for (int j = i - 1; j >= breakPos; j--) {
            if (abs(nums[j] - nums[i]) > limit) {
                breakPos = j;
                breakEle = nums[j];
            }
        }
        cout <<"breakPos:"<< breakPos  <<"breakEle:" << breakEle << endl;
        if(breakEle == -1) {
            dp[i] = dp[i - 1] + 1;
        } else {
            // int j = 0;
            
            // cout <<"breakPos:"<< breakPos  <<"i:" << i << endl;
            // int temp = start;
            // for (j = i - 1; j > start; j--) {
            //     if (abs(nums[i] - nums[j]) > limit) {
            //         start = j;
            //         // cout << "start:" << start << endl;
            //         break;
            //     }
            // }
            dp[i] = i - breakPos;
        }
    }
    for(int i : dp) {
        cout << i << endl;
    }
    return *max_element(dp.begin(), dp.begin() + sz);
}

int longestSubarray_2(vector<int>& nums, int limit){
    map<int, int> m;
    int ans = 0;
    int i = 0;
    for (int j = 0; j < (int)nums.size(); j++) {
        m[nums[j]]++;
        while (m.rbegin()->first - m.begin()->first > limit) {
            m[nums[i]]--;
            if (m[nums[i]] == 0) {
                m.erase(nums[i]);
            }
            i++;
        }
        ans = max(ans, j - i + 1);
    }
    return ans;
}

int main() {
    vector<int> nums = {8, 8, 2, 4, 7};
    int limit = 4;
    cout << longestSubarray_2(nums, limit);    
}