#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int cand = -1;
    int cnt = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(cand == nums[i]) cnt++;
        else if(--cnt < 0) {
            cnt = 1;
            cand = nums[i];
        }
    }
    cout << cnt << endl;
    return cand;
}

int main() {
    vector<int> nums = {2, 2, 1};
    cout << majorityElement(nums) << endl;
    return 0;
}