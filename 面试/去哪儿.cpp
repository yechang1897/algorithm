#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int fun(vector<int> nums) {
    sort(nums.begin(), nums.end());
    vector<int> t;
    int sz = nums.size();
    int tsum = nums[sz - 1];
    t.push_back(tsum);
    for (int i = sz - 2; i >= 0; i--) {
        tsum += nums[i];
        if(tsum < 0) {
            break;
        } else {
            t.push_back(nums[i]);
        }
    }
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        res += (nums.size() - i);
    }
    return res;
}

int main() {

}