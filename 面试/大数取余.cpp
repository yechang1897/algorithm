#include<iostream>
#include<vector>
using namespace std;

int bigmod(vector<int> nums, int mod) {
    int sz = nums.size();
    int res = 0;
    for(int i = 0; i < sz; i++) {
        res = 10 * res + nums[i];
        if(res > mod) {
            res = res % mod;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1,3,4,5,6,7,8,1,2,3};
    int mod = 21;
    cout << bigmod(nums, mod);
    return 0;
}