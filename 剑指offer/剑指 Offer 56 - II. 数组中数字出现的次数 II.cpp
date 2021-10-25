#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int sz = nums.size();
    int res = 0;

    for(int i = 0; i < 32; i++) {
        int t = 0;
        for(int j = 0; j < sz; j++) {
            // cout << (nums[j] & (1 << i)) << endl;
            if((nums[j] & (1 << i)) != 0) t++;
            
        }
        // cout << t <<" " << i <<endl;
        if(t % 3 == 1) {
            res |= (1 << i); 
            // cout << i << endl;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {3, 4, 3, 3};
    cout << singleNumber(nums) << endl;
    return 0;
}